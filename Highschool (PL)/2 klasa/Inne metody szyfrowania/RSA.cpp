#include <iostream>
#include <cmath>
using namespace std;
long long unsigned int NWD(int x,int y)
	{if(x==0 or y==0) return x+y;
	if(y>x) return NWD(x,y%x);
	else return NWD(x%y,y);
	};
int main()
	{long long unsigned int p,q,m,m1 ,n,e,d,c,c1,w,t;
	cout<<" Podaj dwie liczby pierwsze bliskie sobie "<<endl;
	cin>>p>>q;
	n=p*q;
	cout<<" n= "<<n<<endl;
	for(e=2;;e++)
		{w=(p-1)*(q-1);
		 if(NWD(e,w)==1)
		 	{cout<<" e= "<<e<<endl;
		 	break;
			}
		}
	for(d=1;;d++)
		{if((e*d)%w==1)
			{cout<<" d= "<<d<<endl;
			break;
			}
		}
	cout<<" Podaj liczbe do zaszyfrowania "<<endl;
	cin>>m;
	c1=pow(m,e);
	c=c1%n;
	cout<<" Zaszyfrowana= "<<c<<endl;
	m1=pow(c,d);
	m=m1%n;
	cout<<" Odszyfrowane= "<<m<<endl;
	}
