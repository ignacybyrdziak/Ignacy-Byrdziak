#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
void zapelniator(int t[],int il)
	{int i;
	 for(i=0;i<il;i++)
	 	{t[i]=rand()%2000-1000;
	 	cout<<t[i]<<endl;
	 	}
	};
int max(int t[],int il)
	{int max=t[0],pozmax=0;
	for(int i=1;i<il;i++)
		{if(t[i]>max)
			{max=t[i];
			pozmax=i;
			}
		}
	return pozmax;	
	}
int main()
{srand(time(NULL));
int n,n1;
cin>>n>>n1;
int tab1[n],tab2[n1];
zapelniator(tab1,n);
cout<<" ******* "<<endl;
zapelniator(tab2,n1);
cout<<" Max w 1 tablicy "<<tab1[max(tab1,n)]<<" na pozycji "<<max(tab1,n)<<endl;
cout<<" Max w 2 tablicy "<<tab1[max(tab2,n1)]<<" na pozycji "<<max(tab2,n1)<<endl;
}


