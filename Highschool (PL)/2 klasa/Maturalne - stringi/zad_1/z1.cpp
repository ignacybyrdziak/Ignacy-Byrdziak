#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
int main()
{string w;
int i,x,il,il1=0,il2=0,ila=0,ilb=0,ilc1=0,ilc0=0,ild=0;
ifstream odczyt("napisy.txt");
ofstream zapis("zadanie4.txt");
int tab[17];
for(i=0;i<17;i++)
	tab[i]=0;
while(!odczyt.eof())
	{odczyt>>w;
	x=w.size();
	if(x%2==0)
		il1++;
		
	for(i=0,il=0;i<w.size();i++)
		{if(w[i]=='0')
			il++;	
		}	
	if(il==x/2)
		il2++;
		
	if(il==0)
		ilc1++;
	else
		ilc0++;
	
	tab[x]++;
	}
zapis<<ila<<endl;
zapis<<ilb<<endl;
zapis<<ilc0<<" "<<ilc1<<endl;
for(i=2;i<17;i++)
	zapis<<w[i]<<endl;

}
