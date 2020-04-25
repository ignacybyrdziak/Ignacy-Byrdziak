#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{int kostka [7];
int n,i,x;
	for(i=1;i<7;i++)     //zerowanie kostki
	  	kostka[i]=0;
srand(time(NULL));
cout<<" Podaj liczbê rzutow w";
cin>>n;
	for(i=1;i<=n;i++)
		{x=rand()%6+1;
		cout<<x<<endl;
		kostka[x]++;
		}
cout<<" ******************** "<<endl;
	for(i=1;i<7;i++)
		{cout<<" Wartosc "<<i<<" wypadla "<<kostka[i]<<endl;
		}
return 0;
}
