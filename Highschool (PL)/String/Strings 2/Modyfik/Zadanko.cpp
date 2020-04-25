#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cstring>
using namespace std;
int main()
{srand(time(NULL));
int i,j,m,n,x;
string w;
ofstream zapis("wynik.txt");
cout<<" Podaj ilosc wyrazow ";
cin>>m;
for(i=0;i<m;i++)
	{cout<<" Podaj ilosc liter ";
	cin>>n;
	w="";
	for(j=0;j<n;j++)
		{x=rand()%26+97;
		 w=w+(char)x;
		}
	zapis<<w<<endl;
	}
return 0;
}
