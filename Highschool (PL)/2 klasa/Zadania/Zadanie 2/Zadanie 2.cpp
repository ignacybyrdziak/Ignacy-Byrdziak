#include <iostream>
using namespace std;
int main()
	{int s=0,n;
	 cout<<" Podaj n ";
	 cin>>n;
	 	for(int i;n>0;n=n/10)
	 		{i=n%10;
			 s=s+(i*i);
			}
		if(s>=100 && s<=999)
			cout<<" Tak ";
		else
			cout<<" Nie ";
		cout<<s;
return 0;
	}

