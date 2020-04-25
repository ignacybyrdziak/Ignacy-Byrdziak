#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
int main()
{string w;
int il1=0,il2=0;
ifstream odczyt ("abc.txt");
 ofstream zapis ("odp(abc).txt");
 	while(!odczyt.eof())
 		{odczyt>>w;
		 if(w[0]!=w[1] && w[1]!=w[2] && w[0]!=w[2])
 			il1++;
		 if(w[0]==w[2])
		 	il2++;
		}
	zapis<<il1<<endl<<il2;
}
