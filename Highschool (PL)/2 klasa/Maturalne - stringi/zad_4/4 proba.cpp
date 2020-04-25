#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
bool pierwsza(int s)
	{if(s<4) return true;
	if(s%2==0) return false;
	int k=3;
	while(k<=sqrt(s))
		{if(s%k==0) return false;
		k+=2;
		}
	return true;
	};
bool rosn (string w)
	{int i;
	 for(i=0;i<w.size()-1;i++)
	 	{if(w[i]>=w[i+1]) return false;
		}
	return true;	
	}
int main()
{ifstream odczyt("NAPIS.txt");
 ofstream zapis("zadanie_proba.txt");
 int i,j=0,s,ila=0,z=0;
 vector <string> popr;
 string w;
 zapis<<" B)"<<endl;
 while(!odczyt.eof())
	{odczyt>>w;
	popr.push_back(w);
	z++;
 	for(i=0,s=0;i<w.size();i++)
 		s+=w[i];
 	if(pierwsza(s)==true)
 		ila++;
 	if(rosn(w)==true)
 		zapis<<w<<endl;
	}
sort(popr.begin(),popr.end());
zapis<<" ******* "<<endl;
for(i=0;i<popr.size();)
	{if(popr[i]!=popr[i+1])
		popr.erase(popr.begin()+i);
	else
		{popr.erase(popr.begin()+i+1);
		if(popr[i]!=popr[i+1])
			i++;
		}
	}
for(i=0;i<popr.size();i++)
	zapis<<popr[i]<<endl;
zapis<<" A) "<<ila<<endl;
}


