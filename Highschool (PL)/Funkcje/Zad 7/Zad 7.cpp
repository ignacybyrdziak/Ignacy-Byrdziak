#include <iostream>
#include <cstring>
using namespace std;
string bin(int x)
	{string s="";
	for(;x>0;x/=2)
		{if(x%2==0) 
			s='0'+s;
		else
			s='1'+s;
		}
	return s;
	}
int main()
{int x;
cin>>x;
cout<<x<<" to w bin "<<bin(x);
}
