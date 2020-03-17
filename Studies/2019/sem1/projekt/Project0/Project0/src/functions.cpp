#include <iostream>	
#include <string>
#include <sstream>
#include <fstream>

#include "functions.h"

void Add_Nodes(node *&nRoot, const text &line)
{
	std::istringstream str(line);
	int index;
	text label;
	char oper;
	double atri;
	text n_left, n_right;

	str >> index >> label >> oper >> atri >> n_left >> n_right;

	node *newNode = new node{ index, label, oper, atri, n_left, n_right, nullptr, nullptr, false, nullptr };

	if (!nRoot)
	{
		nRoot = newNode;
		return;
	}
	Add_Node_To_Tail(nRoot, newNode);
	return;
}

void Add_Node_To_Tail(node *nHead, node *newNode)
{
	node *ptr = nHead;
	while (ptr->nNext)
		ptr = ptr->nNext;
	ptr->nNext = newNode;
	return;
};

void Make_Tree(node *&nRoot, node *nHead)
{
	if (nRoot->n_left == "" || nRoot->n_right == "") return;

	if (!nRoot->left) {
		nRoot->left = Find_Node(nHead, nRoot->n_left);
		Make_Tree(nRoot->left, nHead);
	}

	if (!nRoot->right) {
		nRoot->right = Find_Node(nHead, nRoot->n_right);
		Make_Tree(nRoot->right, nHead);
	}
	return;
}

node *Find_Node(node *nHead, text label)
{
	std::stringstream str(label);
	int idx;
	if (str >> idx)
	{
		node* ptr = nHead->nNext;
		while (ptr)
		{
			if (ptr->index == idx)
				return ptr;
			ptr = ptr->nNext;
		}
	}
	node *foundNode = new node{ -1, label , ' ', 0.0, "", "", nullptr, nullptr, true, nullptr };
	Add_Node_To_Tail(nHead, foundNode);
	return foundNode;
}

int Add_Labels(person *&head, text label, int k)
{
	if (!head)
	{
		head = new person{ label, 0.0, false, nullptr };
		k++;
		return k;
	}
	else
	{
		person *tmp = new person{ label, 0.0, false, nullptr };
		auto p = head;
		while (p->next)
			p = p->next;
		p->next = tmp;
	}
	k++;
	return k;
}

void New_Values(person *&head, double atri)
{				
	if (head->check == false)
	{
		head->atri = atri;
		head->check = true;
		return;
	}
	else
	{
		auto p = head;
		while (p->next && p->next->check !=false)
			p = p->next;
		p->next->atri = atri;
		p->next->check = true;
	}
	return;
}

text Check_Tree(node * pRoot, person *&pHead)
{
	if (pRoot->leaf == true)
		return pRoot->label;
	double atri = Find_Value(pHead, pRoot->label);
	if (pRoot->oper == '>' && atri > pRoot->atri || pRoot->oper == '<' && atri < pRoot->atri)
		return Check_Tree(pRoot->right, pHead);
	return Check_Tree(pRoot->left, pHead);
}

double Find_Value(person *pHead, text label)
{
	if (!(pHead->label == label))
		return Find_Value(pHead->next, label);
	else
		return pHead->atri;
}

void Add_End_Label(endlist *&endhead, double v, text label)
{
	if (!endhead)
		endhead = new endlist{ label, nullptr, nullptr };
	if (endhead->label != label)
	{
		Add_End_Label(endhead->bNext, v, label);
		return;
	}
	Value *&values = endhead->sNext;
	Add_To_Label(values, v);
	return;
}

void Add_To_Label(Value *&values, double v)
{
	auto &p = values;
	if (!p)
	{
		p = new Value{ v, nullptr };
		return;
	}
	Add_To_Label(p->next, v);
	return;
}

void To_File(endlist *endhead, int k, std::ofstream& save_o)
{
	while (endhead)
	{
		save_o << endhead->label << std::endl;
		auto p = endhead->sNext;
		while (p)
		{
			for (int i = 0; i < k; i++)
			{
				save_o << p->atri << " ";
				p = p->next;
			}
			save_o << std::endl;
		}
		endhead = endhead->bNext;
	}
	return;
}
