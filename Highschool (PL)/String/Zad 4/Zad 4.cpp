#include <iostream>
#include <cstring>
using namespace std;
int main()
{bool sp;
int i,j;
string w,syl;
cout<<" Podaj wyraz ";
cin>>w;
cout<<" Podaj sylabe ";
cin>>syl;
for(i=0;i<=w.size()-syl.size();i++)	
	{for(sp=true,j=0;j<syl.size();j++)
		{if(w[i+j]!=syl[j])
			{sp=false;
			break;
			}
		}
	cout<<sp<<endl;
	if(sp==true)
		 break;
	}
		
if(sp==true)
	cout<<" Jest ";
else
	cout<<" Nie jest ";
return 0;
}
