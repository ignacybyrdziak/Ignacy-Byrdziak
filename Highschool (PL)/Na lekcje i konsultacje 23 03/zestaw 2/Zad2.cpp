#include <iostream>
using namespace std;
int sum(int x,int sys)
	{
		int s=0;
		while(x!=0)
			{s+=x%sys;
			 x=x/sys;
			}
		return s;	
	}
int main()
	{
		int i,l,suma10;
		cout<<" Podaj liczebnik: "<<endl;
		cin>>l;
		suma10=sum(l,10);
		for(i=2;i<10;i++)
			{
				if(sum(l,i)==suma10)
				cout<<i<<endl;
			}
	
		return 0;			
	}
