#include <iostream>
using namespace std;
int main ()
{int a,b,c,d,il;
il=0;
cout<<" Podaj 4 liczby ";
cin>>a>>b>>c>>d;
	if (a%2==1 && a%7==0)
	il++;
	 if (b%2==1 && b%7==0)
	 il++;
	  if (c%2==1 && c%7==0)
	  il++;
     	if (d%2==1 && d%7==0)
    	il++;
cout<<" Liczb nieparzystych podzielnych przez 7 jest: "<<il;
return 0;
    	
	
}
