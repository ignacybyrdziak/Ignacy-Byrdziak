#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
bool ist_tr(float a,float b,float c)
	{if(a<=0 || b<=0 || c<=0) return false;
 	 float p=(a+b+c)/2;
 	 if(p>a && p>b && p>c) return true;
 	 return false;
	};
string rodzaj_tr(float a,float b,float c)
	{if(a>c) swap(a,c);
	 if(b>c) swap(b,c);
	 if(a*a+b*b>c*c) return " ostrokatny ";
	 if(a*a+b*b<c*c) return " rozwartokatny ";
	return " prostokatny ";
	};
float pole_tr(float a,float b,float c)
	{float p=(a+b+c)/2;
	 return sqrt(p*(p-a)*(p-b)*(p-c));
	};
int main()
{float x,y,z;
cin>>x>>y>>z;
if(ist_tr(x,y,z))
	{cout<<" Trojkat "<<rodzaj_tr(x,y,z)<<" pole wynosi "<<pole_tr(x,y,z)<<endl;
	}
else
	cout<<" Trojkat nie istnieje ";
}
