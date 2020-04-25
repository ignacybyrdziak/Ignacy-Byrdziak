#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{int n,i,j=0;
cout<<" Podaj n ";
cin>>n;
int tab1 [n],tab2 [n-2];
srand(time(NULL));
	for(i=0;i<n;i++)
		{tab1 [i]=rand()%1001;
		cout<<tab1[i]<<endl;
		}
cout<<" ******************** "<<endl;
	for(i=1;i<n-1;i++)
		{if(tab1[i-1]%2==0 && tab1[i+1]%2==0)
			{tab2[j]=tab1[i];
			j++;
			}
		}
	for(i=0;i<j;i++)
		cout<<tab2[i]<<endl;
return 0;
}
