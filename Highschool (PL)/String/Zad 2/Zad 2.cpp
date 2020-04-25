#include <iostream>
#include <cstring>
using namespace std;
int main()
{string p;
char x;
cout<<" Podaj wyraz ";
cin>>p;
cout<<" Podaj litere ";
cin>>x;
int l=0,i;
for(i=0;i<p.size();i++)
	{if(p[i]==x)
		l++;
	}
cout<<" Litera "<<x<<" wystepuje w wyrazie "<<p<<" "<<l<<" razy. ";
}
