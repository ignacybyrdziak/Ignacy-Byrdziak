#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{int n,i,j=0,sum=0;
cout<<" Podaj n ";
cin>>n;
int tab1 [n+2],tab2 [n];
srand(time(NULL));
	for(i=0;i<n;i++)
		{tab1 [i]=rand()%2001-1000;
		cout<<tab1[i]<<endl;
		}
cout<<" ******************** "<<endl;
tab1[n]=tab1[0];
tab1[n+1]=tab1[1];
	for(i=1;i<n-1;i++)
		{sum=tab1[i-1]+tab1[i]+tab1[i+1];
		tab2[j]+=sum;
			j++;
			}
		}
	for(i=0;i<j;i++)
		cout<<tab2[i]<<endl;
return 0;
}
