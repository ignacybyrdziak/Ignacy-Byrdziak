#include <iostream>
using namespace std;
unsigned int sil(int n)
	{if(n<2) return 1;
	 else
	 	return n*sil(n-1);
	}
int main()
	{int n;
	cout<<" Podaj n "<<endl;
	cin>>n;
	cout<<" Silnia wynosi "<<sil(n);
	return 0;
	}
