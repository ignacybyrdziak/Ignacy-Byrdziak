#include <iostream>
using namespace std;
int main()
{float x,y;
char wybor;
cout<<" Podaj 2 liczby ";
cin>>x>>y;
cout<<" +-suma\n --roznica\n *-iloczyn\n /-iloraz\n ";
cin>>wybor;
	switch(wybor)
		{case '+': cout<<" Suma wynosi "<<x+y;break;
		 case '-': cout<<" Roznica wynosi "<<x-y;break;
		 case '*': cout<<" Iloczyn wynosi "<<x*y;break;
		 case '/': if(y!=0)
		 cout<<" Iloraz wynosi "<<x/y;
		 		 else
		 cout<<" Nie dziel przez 0 ";
		 break;
default: cout<<" Wybrales zly operator ";
}
return 0;
}
