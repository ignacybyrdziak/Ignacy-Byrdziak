#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int dziel(int x)
	{int s=x+1;
	for(int k=2;k<=x/2;k++)
		{if(x%k==0) 
			s=s+k;
		}
	return s;
	};
int main()
{int x,i;
srand(time(NULL));
for(i=0;i<10;i++)
	{x=rand()%99+2;
	 cout<<" Dla liczby "<<x<<" suma dzielnikow wynosi "<<dziel(x)<<endl;
	}
}
