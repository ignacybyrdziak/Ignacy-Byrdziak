#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int main()
{int x,y,i;
float dl;
ifstream odczyt ("wektor.txt");
ofstream zapis  ("dlugosc.txt");
for(i=0;!odczyt.eof();i++)
	{odczyt>>x>>y;
	dl=(float)sqrt(x*x+y*y);
	 zapis<<dl<<endl;
	}
return 0;
}
