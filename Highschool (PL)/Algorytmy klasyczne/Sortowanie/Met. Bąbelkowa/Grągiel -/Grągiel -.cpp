#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
	{srand(time(NULL));
	int i,n,k;
	bool babel=true;
	cout<<" Podaj rozmiar tablicy "<<endl;
	cin>>n;
	int tab[n];
	for(i=0;i<n;i++)
 		{tab[i]=rand()%201-100;
 		 cout<<i+1<<"."<<tab[i]<<endl;
		}
	cout<<" ******* "<<endl;
	while(babel)
		{babel=false;
		k=n-1;
		 for(i=0;i<k;i++)
		 	{if(tab[i]<tab[i+1])
		 		{swap(tab[i],tab[i+1]);
		 		 babel=true;
				}
			}
		} 
for(i=0;i<n;i++)
 	cout<<i+1<<"."<<tab[i]<<endl;
		
}
