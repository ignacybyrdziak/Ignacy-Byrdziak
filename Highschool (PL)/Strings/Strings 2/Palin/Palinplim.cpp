#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
int main()
{int i,n;
string w1,w2;
ofstream zapis ("palindrom.txt");
ifstream odczyt ("wyrazy.txt");
while(!odczyt.eof())
	{odczyt>>w1;
	w2=w1;
	for(i=0;i<w1.size();i++)
		w2[i]=w1[w1.size()-i-1];
	if(w1==w2)
		zapis<<w1<<endl;	
	}
return 0;
}
