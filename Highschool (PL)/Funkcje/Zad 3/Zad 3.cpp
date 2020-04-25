#include <iostream>
using namespace std;
int sil(int x)
	{if(x==0) return 1;
	 int i,s=1;
	 for(i=1;i<=x;i++)
	 	{s*=i;
		}
	return s;
	};
int main()
{int x;
for(x=0;x<=11;x++)
	{cout<<" Silnia dla "<<x<<" wynosi "<<sil(x)<<endl;
	}
}
