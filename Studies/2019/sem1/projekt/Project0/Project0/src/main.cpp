#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
 
#include "functions.h"
#include "structures.h"

#include "CLI11.hpp"

int main(int argc, char* argv[])
{
	CLI::App app{ "DecisionTree" };					//operating on 'main' parameters

	std::string outFile = "out.txt";
	std::string attributesFile = "attrs.txt";
	std::string nodesFile = "nodes.txt";

	app.add_option("-o,--output", outFile, "Name of output file")->check(CLI::NonexistentPath)->required();
	app.add_option("-i", attributesFile, "Name of file containing attributes being sorted")->check(CLI::ExistingFile);
	app.add_option("-t,--tree", nodesFile, "Name of file containing nodes/tree description")->check(CLI::ExistingFile);

	CLI11_PARSE(app, argc, argv);

	std::ofstream save_o(outFile);					
	std::ifstream read_i(attributesFile);
	std::ifstream read_t(nodesFile);

	text line;								//operating on files
	node *nRoot = nullptr;
	while (getline(read_t, line))
		Add_Nodes(nRoot, line);
	node *nHead = nRoot;
	person *head = nullptr;
	endlist *endhead = nullptr;
	text ending;

	Make_Tree(nRoot, nHead);

	getline(read_i, line);
	std::istringstream str(line);
	text label;
	double atri;
	int k = 0;

	while (str >> label)
	{
		if (label[0] == '%')
			break;
		k = (Add_Labels(head, label, k));
	}
	str.clear();

	while (getline(read_i, line))
	{
		std::stringstream str2(line);
		while (str2 >> atri)
			New_Values(head, atri);
		label = Check_Tree(nRoot, head);
		auto tmp = head;
		while (tmp != nullptr)
		{
			auto v = tmp->atri;
			Add_End_Label(endhead, v, label);
			tmp->check = false;
			tmp = tmp->next;
		}
		str2.clear();
	}
	To_File(endhead, k, save_o);						

	delete head;										//memory deallocation
	delete endhead;
	delete nHead;
}