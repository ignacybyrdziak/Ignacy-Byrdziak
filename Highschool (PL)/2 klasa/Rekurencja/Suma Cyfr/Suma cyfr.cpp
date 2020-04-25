#include <iostream>
using namespace std;
unsigned int sum(int n)
	{if(n==0)	return 0;
	 if(n>0)	return sum(n/10)+n%10;
	}
int main()
	{int x;
	cout<<" Podaj x "<<endl;
	cin>>x;
	cout<<" Suma cyfr wynosi "<<sum(x);
	return 0;
	}
