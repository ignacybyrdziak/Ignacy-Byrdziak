#include <iostream>
using namespace std;
float wart (int n,float x)
	{float a[n+1],y;
	for(int i=n;i>=0;i--)
		{cout<<" Podaj "<<i<<" wspolczynnik "<<endl;
		 cin>>a[i];
		}
		y=a[n];
		for(int i=n-1;i>=0;i--)
			y=y*x+a[i];
	return y;
	};
int main()
	{int n;
	float x;
	cout<<" Podaj stopien wielomianu "<<endl;
	cin>>n;
	cout<<" Podaj x "<<endl;
	cin>>x;
	cout<<" y= "<<wart(n,x);
	}
