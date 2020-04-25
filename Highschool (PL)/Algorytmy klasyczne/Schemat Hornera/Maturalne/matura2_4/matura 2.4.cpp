#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
string dz_na_tr(int l3)
	{string w="";
	 int x;
	 while(l3>0)
	 	{x=l3%3;
	 	 w=(char)(x+48)+w;
		l3/=3;
		}
	return w;
	};
int tr_na_dz(string l)
	{int y;
	y=l[0]-48;
	for(int i=1;i<l.size();i++)
		y=y*3+l[i]-48;
	return y;
	}
int main()
	{ofstream zapis ("wynik5.txt");
	 ifstream odczyt ("pary.txt");
	 string w1,w2;
	 int s;
	 while(!odczyt.eof())
	 	{s=0;
		 odczyt>>w1>>w2;
	 	s=tr_na_dz(w1)+tr_na_dz(w2);
	 	zapis<<dz_na_tr(s)<<endl;
		}
	return 0;
	}
