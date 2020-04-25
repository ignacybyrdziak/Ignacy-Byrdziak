#include <iostream>
#include <cmath>
using namespace std;
void sito (bool tab[],int n)
	{int i,j;
	 for(i=2;i<=n;i++)
	 	tab[i]=true;
	tab[1]=false;
	for(i=2;i<sqrt(n);i++)
		{if(tab[i])
			{for(j=i*i;j<=n;j+=i)
				tab[j]=false;
			}
		}
	}
int main()
{int i,s,s1,j,il=0,n=100000;
bool tab[n+1];
sito(tab,n);
for(i=1000;i<n;i++)
	{s1=0,s=0;
	if(tab[i]==false)
		continue;	
	for(j=i;j>0;j=j/10)
		s+=j%10;
	if(tab[s]==false)
		continue;
	for(j=i;j>0;j=j/2)
		s1+=j%2;
	if(tab[s1]==false)
		continue;
	il++;
	cout<<il<<". "<<i<<endl;
	}
return 0;
}

