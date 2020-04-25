#include <iostream>
using namespace std;
int z_bin_na_dec(string l)
	{int y;
	y=l[0]-48;
	for(int i=1;i<l.size();i++)
		y=y*2+l[i]-48;
	return y;
	}
int main()
	{string l;
	cout<<" Podaj liczbe "<<endl;
	cin>>l;
	cout<<z_bin_na_dec(l);
	}
