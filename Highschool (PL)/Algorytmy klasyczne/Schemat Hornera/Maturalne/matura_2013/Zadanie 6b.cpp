#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;
int os_na_dz(string l)
	{int y;
	y=l[0]-48;
	for(int i=1;i<l.size();i++)
		y=y*8+l[i]-48;
	return y;
	};
int main()
	{int il=0;
	string l,w;
	stringstream p;
	ifstream odczyt ("dane.txt");
	 ofstream zapis ("wynik.txt");
	 while(!odczyt.eof())
	 	{odczyt>>l;
	 	p<<os_na_dz(l);
		p>>w;
		if(w[0]==w[w.size()-1])
			il++;
		p.clear();
		}
	zapis<<il;
	}
