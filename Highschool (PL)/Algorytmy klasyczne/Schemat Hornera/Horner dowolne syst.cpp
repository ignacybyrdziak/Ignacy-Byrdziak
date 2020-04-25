#include <iostream>
using namespace std;
int z_sys_na_dec(string l,int system)
	{int y;
	y=l[0]-48;
	for(int i=1;i<l.size();i++)
		y=y*system+l[i]-48;
	return y;
	}
int main()
	{string l;
	int x;
	cout<<" Podaj liczbe "<<endl;
	cin>>l;
	cout<<" Podaj system "<<endl;
	cin>>x;
	cout<<z_sys_na_dec(l,x);
	}
