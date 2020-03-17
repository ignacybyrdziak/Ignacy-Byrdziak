#ifndef structures_h
#define structures_h

#include <iostream>
#include <string>
#include <sstream>

typedef std::string text;

struct person							///Athlete with attributes connected to labels
{
	text label;							///Label of athlete's attribute
	double atri;						///Value of athlete's attribute
	bool check;							///Variable to check if value of athlete's attribute is new or not
	person *next;						///Pointer to next athlete

	~person(void)						///Destructor for 'person' element
	{
		delete next;
	}
};

struct Value							///Values in ending list
{
	double atri;						///Value of athlete's attribute (in ending list)
	Value *next;						///Pointer to next value

	~Value(void)						///Destructor for 'Value' element
	{
		delete next;
	}
};

struct endlist							///Ending list
{
	text label;							///Label of discipline
	endlist* bNext;						///Pointer to next label
	Value* sNext;						///Pointer to values in current label

	~endlist(void)						///Destructor for 'endlist' element
	{
		delete bNext;
		delete sNext;
	}
};

struct node								///Node in Decision tree
{
	int index;							///Index of node
	text label;							///Sport discipline in node's condition					///condition
	char oper;							///Operator in node's condition							///condition
	double atri;						///Value of attribute in node's condition				///condition
	text n_left;						///Value of left pointer
	text n_right;						///Value of right pointer
	node *left;							///Pointer to left node
	node *right;						///Pointer to right node
	bool leaf;							///Variable to check if current node is leaf or not
	node *nNext;						///Index of node

	~node(void)							///Destructor for 'node' element
	{
		delete nNext;
	}
};

#endif
