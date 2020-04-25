#include <iostream>
using namespace std;
unsigned int lot(int n,int m)
	{if(m==0) return 1;
	 if(m==n) return 1;
	 return lot(n-1,m-1)+lot(n-1,m);
	}
int main()
	{int n,m;
	cout<<" Podaj n "<<endl;
	cin>>n;
	cout<<" Podaj m "<<endl;
	cin>>m;
	cout<<" Lotto wynosi "<<lot(n,m);
	return 0;
	}
