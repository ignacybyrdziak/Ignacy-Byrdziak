#include <iostream>
#include <cmath>
using namespace std;
void sito (bool tab[],int n)
	{int i,j;
	 for(i=2;i<=n;i++)
	 	tab[i]=true;
	for(i=2;i<sqrt(n);i++)
		{if(tab[i])
			{for(j=i*i;j<=n;j+=i)
				tab[j]=false;
			}
		}
	}
int main()
{int l,k;
cin>>l;
bool t[l+1];
sito(t,l);
for(k=2;k<=l;k++)
	{if(t[k])
		cout<<k<<endl;
}
