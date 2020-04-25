#include <iostream>
#include <cstring>
using namespace std;
string z_dec_na_dow(int l10,int podst)
	{string w="";
	 int x;
	 while(l10>0)
	 	{x=l10%podst;
	 	 w=(char)(x+48)+w;
		l10/=podst;
		}
	return w;
	};
int main()
{int liczba,podstawa;
 cout<<" Podaj liczbe "<<endl;
 cin>>liczba;
 cout<<" Podaj system "<<endl;
 cin>>podstawa;
 cout<<z_dec_na_dow(liczba,podstawa)<<endl;
}
