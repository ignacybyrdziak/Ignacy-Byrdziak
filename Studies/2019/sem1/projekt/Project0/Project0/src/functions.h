#ifndef functions_h
#define functions_h

#include <iostream>
#include <string>
#include <sstream>

#include "structures.h"

/**	Function reads lines from file with structure of the decision tree
@param nRoot pointer to first list element (head)
@param line[in, out] stream to read lines from file with structure of the decision tree
*/
void Add_Nodes(node *&nRoot, const text &line);

/**	Function adds read by Add_Nodes function
@param nHead pointer to first list element (head)
@param newNode value of new node to add
*/
void Add_Node_To_Tail(node *nHead, node *newNode);

/** Function makes tree from Add_Nodes list
@param nRoot pointer to first tree element (head)
@param nHead pointer to first list element (head)
*/
void Make_Tree(node *&nRoot, node *nHead);

/**	Function returns node with given index or label from Add_Nodes list
@param nHead pointer to first tree element (head)
@param label label or index of searched node
*/
node *Find_Node(node *nHead, text label);

/**	Function adds new labels to list which will contain person before it's checked in the tree
@param head pointer to first list element (head)
@param label label to add
@param k counter how many sport disciplines are in file
*/
int Add_Labels(person *&head, text label, int k);

/**	Function adds values of new person's attributes to 'person' list
@param head pointer to first list element (head)
@param atri value of next attribute
*/
void New_Values(person *&head, double atri);

/**	Function checks person and returns sport discipline he will be added to
@param pRoot pointer to first tree element (head)
@param pHead pointer to first lsit element (head)
*/
text Check_Tree(node * pRoot, person *&pHead);

/**	Function returns value of person's attribute in searchedsport discipline
@param pHead pointer to first list element (head)
@param label label for which we are searching attribute
*/
double Find_Value(person *pHead, text label);

/**	Function adds sport disciplines to ending list
@param endhead pointer to first list element (head)
@param v value of attribute
@param label sport discipline
*/
void Add_End_Label(endlist *&endhead, double v, text label);

/**	Function adds values of athlete's attributes to list of sport disciplines
@param values pointer to first list element (head)
@param v value of attribute
*/
void Add_To_Label(Value *&values, double v);

/**	Function saves data from ending list to output file
@param endhead pointer to first list element (head)
@param save_o[in, out] stream to save data to output file
*/
void To_File(endlist *endhead, int k, std::ofstream& save_o);

#endif

