#include <iostream>
#include <cmath> //sqrt, pow (potegi)
using namespace std;
int main ()
{float a,b,c,p,pole;
cout<<" Podaj trzy boki ";
cin>>a>>b>>c;
	if (a<=0 or b<=0 || c<=0) // dwa zapisy or
		{cout<<" Wartosci boków ujemne badz 0 ";
		return 0;}
	  p=(a+b+c)/2;
	if(p>a and p>b && p>c) // dwa zapisy and
		{cout<<" Tak ";
		pole=sqrt(p*(p-a)*(p-b)*(p-c));
		cout<<" Pole wynosi "<<pole;}
	else
		cout<<" Nie ";
}
