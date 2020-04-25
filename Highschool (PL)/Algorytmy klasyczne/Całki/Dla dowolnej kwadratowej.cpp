#include <iostream>
#include <cmath>
using namespace std;
double funkcja(double x)
	{ double a1,b1,c1;
	cout<<" Podaj a "<<endl;
	cin>>a1;
	cout<<" Podaj b "<<endl;
	cin>>b1;
	cout<<" Podaj c "<<endl;
	cin>>c1;
	return a1*x*x+b1*x+c1;
	}
double calka(int n,double a,double b)
	{double P=0;
	 double d=(b-a)/n;
	 double x;
	 for(int k=0;k<n;k++)
	 	{x=a+(d*k)+d/2;
	 	 P=P+d*abs(funkcja(x));
		}
	 return P;
	};
int main()
	{int n;
	double a,b;
	cout<<" Podaj a "<<endl;
	 cin>>a;
	 cout<<" Podaj b "<<endl;
	 cin>>b;
	 cout<<" Podaj n "<<endl;
	 cin>>n;
	 cout<<calka(n,a,b)<<endl;
	 return 0;
	}
