#include <iostream>
#include <fstream>
using namespace std;
int main()
{int s=0,x,i;
float sr;
ifstream odczyt ("nowe.txt");
ofstream zapis  ("wynik.txt");
for(i=0;!odczyt.eof();i++)
	{odczyt>>x;
	 if(x>9 && x<100)
	 	s+=x;
	}
sr=(float)s/i;
zapis<<s<<endl;
zapis<<sr;
return 0;
}
