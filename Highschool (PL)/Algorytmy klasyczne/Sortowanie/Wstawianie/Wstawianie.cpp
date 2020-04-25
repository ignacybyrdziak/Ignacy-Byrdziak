#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{srand(time(NULL));
int i,n,k,elem;
cout<<" Podaj rozmiar tablicy "<<endl;
cin>>n;
int tab[n];
for(i=0;i<n;i++)
	{tab[i]=rand()%201-100;
	 cout<<i+1<<"."<<tab[i]<<endl;
	}
cout<<" ******* "<<endl;
for(i=1;i<n;i++)
	{elem=tab[i];
	 k=i-1;
	 while(k>=0 && tab[k]>elem)
	 	{tab[k+1]=tab[k];
	 	 k--;
		}
	 tab[k+1]=elem;
	}
for(i=0;i<n;i++)
	 cout<<i+1<<"."<<tab[i]<<endl;
}

