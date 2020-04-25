#include <iostream>
#include <cstring>
using namespace std;
int main()
{string p;
cout<<" Podaj wyraz ";
cin>>p;
int l=0,i;
for(i=0;i<p.size();i++)
	{if(p[i]=='a')
		l++;
	}
cout<<" Litera a wystepuje "<<l<<" razy. ";
}
