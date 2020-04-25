#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;
int main()
{int n,k,i;
bool p;
ifstream odczyt ("liczby.txt");
ofstream zapis ("pierwsze.txt");
for(;odczyt.eof();)
	{odczyt>>i;
	p=true;
	if(i>=4)
			if(i%2==0)
				p=false;
			else
				{k=3;
				while(k<=sqrt(i))
					{if(i%k==0)
						{p=false;
						break;}
					else
						k=k+2;
					}
			}
if(p==true)
	zapis<<i<<endl;
	}
return 0;
}
