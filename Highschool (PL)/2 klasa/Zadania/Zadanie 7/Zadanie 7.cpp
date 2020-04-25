#include <iostream>
#include <cmath>
using namespace std;
int main()
{int a,b,c;
	for(a=2;a<=48;a++)
		{for(b=a+1;b<=49;b++)
			{for(c=b+1;c<=50;c++)
				{if(a*a+b*b==c*c)
					cout<<a<<" "<<b<<" "<<c<<endl;
				}
			}
		}
return 0;
}

