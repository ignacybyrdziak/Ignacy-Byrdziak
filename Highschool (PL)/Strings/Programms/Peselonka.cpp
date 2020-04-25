#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
int main()
{int i,n,s;
string p;
bool t;
ifstream odczyt("pesel_test.txt");
while(!odczyt.eof())
	{odczyt>>p;
	if(p.size()!=11)
		{cout<<p<<" - Blad1 "<<endl;
		 continue;
		}
	for(i=0,t=true;i<p.size();i++)
		{if(p[i]<48 || p[i]>57)
			{t=false;
			break;
			}
		}
	if(t==false)
	{cout<<p<<" - Blad2 "<<endl;
	continue;
	}
	s=0;	
	s=p[0]-48+3*(p[1]-48)+7*(p[2]-48)+9*(p[3]-48)+1*(p[4]-48)+3*(p[5]-48)+7*(p[6]-48)+9*(p[7]-48)+1*(p[8]-48)+3*(p[9]-48)+1*(p[10]-48);
	if(s%10!=0)
		cout<<p<<" - Blad3 "<<endl;
	else	
		{cout<<p<<" - "<<" Data urodzenia: ";	
		cout<<p[4]<<p[5]<<".";
		if(p[2]>=50)
			cout<<p[2]-50<<p[3]<<".20"<<p[0]<<p[1]<<" - ";
		else
			cout<<p[2]<<p[3]<<".19"<<p[0]<<p[1]<<" - ";
		if(p[9]%2==0)
			cout<<"kobieta"<<endl;
		else
			cout<<"mezczyzna"<<endl;
		}
	}
}
