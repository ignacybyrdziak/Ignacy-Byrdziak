#include <iostream>
using namespace std;
unsigned int kosz(int n)
	{if(n==1) return 1;
	 if(n==2) return 2;
	 if(n==3) return 4;
	 if(n>2) return kosz(n-1)+kosz(n-2)+kosz(n-3);
	};
int main()
	{int n;
	cout<<" Podaj n "<<endl;
	cin>>n;
	cout<<" Liczba mozliwosci wynosi "<<kosz(n);
	return 0;
	}
