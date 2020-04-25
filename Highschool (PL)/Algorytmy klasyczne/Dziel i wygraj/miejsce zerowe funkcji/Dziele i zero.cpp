#include <iostream>
#include <cmath>
using namespace std;
float f(float x)
	{return x*x*x-x-2;
	}
int main()
{float a,b,d,x;
 cin>>a>>b>>d;
 while(b-a>d)
 	{x=(a+b)/2;
 	 if(f(x)==0)
 	 	{cout<<" 1M.Z.= "<<x;
 	 	 return 0;
		}
	 if(f(a)*f(b)>0)
	 	a=x;
	else
		b=x;
	}
	cout<<" 0M.Z.= "<<(a+b)/2;
	return 0;

}
