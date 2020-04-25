#include <iostream>
using namespace std;
int main()
{float x,y;
int wybor;
cout<<" Podaj 2 liczby ";
cin>>x>>y;
cout<<" 1-suma\n 2-roznica\n 3-iloczyn\n 4-iloraz\n ";
cin>>wybor;
	switch(wybor)
		{case 1: cout<<" Suma wynosi "<<x+y;break;
		 case 2: cout<<" Roznica wynosi "<<x-y;break;
		 case 3: cout<<" Iloczyn wynosi "<<x*y;break;
		 case 4: if(y!=0)
		 cout<<" Iloraz wynosi "<<x/y;
		 		 else
		 cout<<" Nie dziel przez 0 ";
		 break;
default: cout<<" Wybrales zly operator ";
}
return 0;
}
