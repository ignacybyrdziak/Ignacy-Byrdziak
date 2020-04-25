#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{srand(time(NULL));
int i,n,k,j,g=0,max;
cout<<" Podaj rozmiar tablicy "<<endl;
cin>>n;
int tab[n];
for(i=0;i<n;i++)
	{tab[i]=rand()%11;
	 cout<<i+1<<"."<<tab[i]<<endl;
	}
cout<<" ******* "<<endl;
max=tab[0];
for(i=1;i<n;i++)
	{if(tab[i]>max)
		max=tab[i];
	}
int tab_pom[max+1];
for(i=0;i<=max;i++)
	tab_pom[i]=0;
for(i=0;i<n;i++)
	{tab_pom[tab[i]]++;
	}
for(i=0;i<=max;i++)
	cout<<i<<"."<<tab_pom[i]<<endl;
cout<<" ******* "<<endl;
for(i=0,g=0;i<=max;i++)
	{j=tab_pom[i];
	for(;j>0;g++,j--)
		tab[g]=i;
	}
for(i=0;i<n;i++)
	cout<<i<<"."<<tab[i]<<endl;
}
