#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
string szyfr(string w,string k)
	{for(int i=0,j=0;i<w.size();i++)
		{w[i]=w[i]+k[j]-64;
		if(w[i]>90) w[i]-=26;
		j++;
		if(j==k.size()) j=0;
		}
	return w;
	}
string odszyfr(string w,string k)
	{for(int i=0,j=0;i<w.size();i++)
	{w[i]=w[i]-k[j]+64;
	if(w[i]<65) w[i]+=26;
	j++;
	if(j==k.size()) j=0;
	}
	return w;
	}
int main()
{string w,w1,k,k1;
ifstream odczyt1a ("tj.txt");
 ifstream odczyt2a ("klucze1.txt");
 ifstream odczyt1b ("sz.txt");
 ifstream odczyt2b ("klucze2.txt");
 ofstream zapisa ("wynik4a.txt");
 ofstream zapisb ("wynik4b.txt");
 while(!odczyt1a.eof())
 	{odczyt1a>>w;
 	odczyt2a>>k;
 	zapisa<<szyfr(w,k)<<endl;
 	}
while(!odczyt1b.eof())
 	{odczyt1b>>w1;
 	odczyt2b>>k1;
 	zapisb<<odszyfr(w1,k1)<<endl;
 	}
return 0;
}
