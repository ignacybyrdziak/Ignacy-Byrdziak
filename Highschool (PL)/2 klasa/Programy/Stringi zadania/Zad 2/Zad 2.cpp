#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
int main()
{int i,il1=0,il2=0,s,il3=0,j;
string onr;
ifstream odczyt("telefony.txt");
ofstream zapis ("odp.txt");
while(!odczyt.eof())
	{odczyt>>onr;
	if(onr[0]=='5' && onr[1]=='1' && onr[2]=='1')
		il1++;
	//======================================
	s=0;
	for(i=0;i<9;i++)	
		{int a=onr[i]-48;
		if(a%2==0)
			s+=a;
		}
		if(s>42)
			il2++;
	//======================================
	for(i=0,j=0;i<9;i++)
		{if(onr[i]=='1')
			j++;
		if(j==4)
			{il3++;
			cout<<il3<<endl;
			break;
			}
		}
		
	
	}
zapis<<il1<<endl;
zapis<<il2<<endl;
zapis<<il3<<endl;
}

	

