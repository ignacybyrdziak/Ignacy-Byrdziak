//#include <iostream>													//powtórka z drzew od Pana Marka
//using namespace std;
//
//
//struct TE
//{
//	TE *left, *right;
//	int val;
//};
//
//void TEAdd(int v, TE* &root)
//{
//	if (!root)
//		root = new TE{ nullptr, nullptr,v };
//	else
//		if (v < root->val)
//			TEAdd(v, root->left);
//		else
//			TEAdd(v, root->right);
//}
//
//void TEAddIter1(int v, TE* &root)
//{
//	if (!root)
//		root = new TE{ nullptr, nullptr,v };
//	else
//	{
//		auto wsk = root;
//		while (wsk)
//		{
//			if (v < wsk->val)
//			{
//				if (wsk->left)
//					wsk = wsk->left;
//				else
//				{
//					wsk->left = new TE{ nullptr, nullptr, v };
//					return;
//				}
//
//			}
//			else
//			{
//				if (wsk->right)
//					wsk = wsk->right;
//				else
//				{
//					wsk->right = new TE{ nullptr, nullptr, v };
//					return;
//				}
//			}
//		}
//
//	}
//}
//
//void TEAddIter2(int v, TE* &root)
//{
//	TE** ptr = &root;
//	while (*ptr)
//		if (v < (*ptr)->val)
//			ptr = &(*ptr)->left;
//		else
//			ptr = &(*ptr)->right;
//	*ptr = new TE{ nullptr,nullptr, v };
//}
//
//struct LElem
//{
//	int val;
//	LElem* next;
//};
//
//
//bool Dodaj(int v, LElem* & head)
//{
//	if (!head || v < head->val)
//	{
//		head = new LElem{ v, head };
//		return true;
//	}
//	auto ptr = head;
//	while (ptr->next && v >= ptr->next->val)
//	{
//		if (v == ptr->next->val)
//			return false;
//		ptr = ptr->next;
//	}
//	ptr->next = new LElem{ v, ptr->next };
//	return true;
//}
//
//
//int main()
//{
//	LElem* glowa = nullptr;
//	Dodaj(10, glowa);
//	Dodaj(5, glowa);
//	Dodaj(0, glowa);
//
//	Dodaj(10, glowa);
//	Dodaj(7, glowa);
//	Dodaj(10, glowa);
//	Dodaj(5, glowa);
//	return 0;
//}