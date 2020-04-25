#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
int main()
{int i,il;
string w;
ifstream odczyt("wyrazy.txt");
ofstream zapis ("zlita.txt");
while(!odczyt.eof())
	{odczyt>>w;
	for(i=0,il=0;i<w.size();i++)
		{if(w[i]=='a')
			il++;
		}
	if(il>=2)
		zapis<<w<<endl;
	}
return 0;	
}
