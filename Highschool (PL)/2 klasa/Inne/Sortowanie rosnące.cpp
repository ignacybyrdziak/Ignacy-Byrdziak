#include <iostream>
using namespace std;
int main()
{float x,y,z;
cout<< " Podaj x, y i z";
cin>>x>>y>>z;
if(x>y)
	{if(x>z)
		{if(y>z)
		 {cout<<z<< ";" <<y<< ";" <<x;}
		 else
		 {cout<<y<< ";" <<z<< ";" <<x;}}
	else
	{cout<<y<< ";" <<x<< "," <<z;}}
else
	{if(z>y)
		{cout<<x<< ";" <<y<< ";" <<z;}
	else
	if(z>x)
		{cout<<x<< ";" <<z<< ";" <<y;}
		else
		{cout<<z<< ";" <<x<< ";" <<y;}}
return 0;}//Dziêujê!
