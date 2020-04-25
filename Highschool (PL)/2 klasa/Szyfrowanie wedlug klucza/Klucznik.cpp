#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
string szyfron(string wyr,int klucz)
	{klucz=klucz%26;
	for(int i=0;i<wyr.size();i++)
		{wyr[i]+=klucz;
		if(wyr[i]>122)
			wyr[i]-=26;
		}
	return wyr;
	};
string odszyfron(string wyr,int klucz1)
	{klucz1=klucz1%26;
	for(int i=0;i<wyr.size();i++)
		{wyr[i]-=klucz1;
		if(wyr[i]<97)
			wyr[i]+=26;
		}
		return wyr;
	};
int main()
{int klucz,klucz1;
string wyr;
ifstream odczyt ("wyrazy.txt");
ofstream zapis ("szyfrowane.txt");
ofstream zapis1 ("odszyfrowane.txt");
cout<<" Podaj klucz "<<endl;
cin>>klucz;
cout<<" Podaj klucz1 "<<endl;
cin>>klucz1;
while(!odczyt.eof())
	{odczyt>>wyr;
	zapis<<szyfron(wyr,klucz)<<endl;
	zapis1<<odszyfron(wyr,klucz1)<<endl;
	}
return 0;
}
