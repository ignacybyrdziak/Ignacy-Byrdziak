#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;
bool pierwsza(int l)
	{if(l<4) return true;
	if(l%2==0) return false;
	int k=3;
	while(k<=sqrt(l))
		{if(l%k==0) return false;
		k+=2;
		}
	return true;
	};
int main()
{int n,i;
srand(time(NULL));
for(i=1;i<=10;i++)
	{n=rand()%999+2;
	if(pierwsza(n))
		cout<<n<<" Jest pierwsza "<<endl;
	else
		cout<<n<<" Jest zlozona "<<endl;
	}
}
