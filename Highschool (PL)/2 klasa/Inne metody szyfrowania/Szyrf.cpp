#include <iostream>
#include <cstring>
using namespace std;
int main()
{int i,j,j1,i1,w;
string slowo,slowo1,slowo2,klucz;
int tab [26][26];
for(i=0;i<26;i++)
	{for(j=0;j<26;j++)
		if(i+j+65>90)
			tab[i][j]=j+i+65-26;
		else
			tab[i][j]=j+i+65;
	}
cout<<" Podaj slowo jakies "<<endl;
cin>>slowo;
cout<<" Podaj klucz "<<endl;
cin>>klucz;
slowo1=slowo;
slowo2=slowo1;
for(i=0,j=0;i<slowo.size();i++,j++)
	{if(j>=klucz.size())
		j=0;
	slowo1[i]=tab[slowo[i]-65][klucz[j]-65];
	}
cout<<" Zaskodowany: "<<slowo1<<endl;
for(i=0,j=0;i<slowo1.size();i++,j++)
	{if(j>=klucz.size())
		j=0;
	for(int g=0;g<26;g++)
		{if(tab[klucz[j]][g]==slowo1[i])
			slowo2[i]=tab[0][g];
		}
	
	}
cout<<" Odkodowany: "<<slowo2<<endl;
}
