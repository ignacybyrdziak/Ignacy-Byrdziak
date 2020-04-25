#include <iostream>
#include <fstream>
#include<cstdlib>
#include <ctime>
#include <vector>
using namespace std;
int main()
{int x,i;
vector <int> tab;
ofstream zapis("wynik.txt");
ifstream odczyt("dane.txt");
if(!odczyt)
{cout<<" Brak ";
 return 1;
}
	while(!odczyt.eof())
		{odczyt>>x;
		tab.push_back(x);
		}
for(i=0;i<tab.size();i++)
	cout<<tab[i]<<endl;
cout<<"*************"<<endl;
for(i=0;i<tab.size();i++)
	{if(tab[i]%3==0)
		{zapis<<tab[i]<<endl;
		cout<<tab[i]<<endl;
		}
	}
return 0;
}
