#include <iostream>
using namespace std;
int main()
{int a,b,c,d,il;
cout<<" Podaj cztery liczby dwucyfrowe ";
cin>>a>>b>>c>>d;
il=0;
	if(a>9 && a<100 && a%2==0)
	il++;
	  if(b>9 && b<100 && b%2==0)
	  il++;
	    if(c>9 && c<100 && c%2==0)
	    il++;
	      if(d>9 && d<100 && d%2==0)
	      il++;
cout<<" Liczb dwucyfrowych parzystych "<<il;
return 0;
}
