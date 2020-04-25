#include <iostream>
#include <cstring>
#include <fstream>
#include <algorithm>
using namespace std;
int main()
{int i,n;
string w1,w2,pom1,pom2;
ofstream zapis ("anagram.txt");
ifstream odczyt ("wyrazy.txt");
while(!odczyt.eof())
	{odczyt>>w1>>w2;
	pom1=w1;
	pom2=w2;
	if(w1.size()==w2.size())
		{sort(w1.begin(),w1.end());
		 sort(w2.begin(),w2.end());
		}
	if(w1==w2)
		zapis<<pom1<<" "<<pom2<<endl;	
	}
return 0;
}
