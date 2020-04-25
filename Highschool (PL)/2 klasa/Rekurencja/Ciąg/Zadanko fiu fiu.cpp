#include <iostream>
using namespace std;
int ciag(int n)
	{if(n<=1) return 3;
	 else 
	 	return ciag(n-1)*5+2;
	}
int main()
	{int n;
	cout<<" Podaj n "<<endl;
	cin>>n;
	cout<<" Ciagnik "<<ciag(n);
	return 0;
	}
