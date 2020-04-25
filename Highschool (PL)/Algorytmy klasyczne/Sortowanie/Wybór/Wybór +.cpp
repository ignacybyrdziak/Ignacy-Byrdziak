#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
	{srand(time(NULL));
	int i,n,k;
	cout<<" Podaj rozmiar tablicy "<<endl;
	cin>>n;
	int tab[n];
	for(i=0;i<n;i++)
 		{tab[i]=rand()%201-100;
 		 cout<<i+1<<"."<<tab[i]<<endl;
		}
	
for(i=0;i<n;i++)
 	cout<<i+1<<"."<<tab[i]<<endl;
		
}
