#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{int n,i,max,min,pozmax,pozmin;
srand(time(NULL));
cout<<" Podaj ilosc liczb ";
cin>>n;
int dane [n];
	for(i=0;i<n;i++)
			{dane[i]=rand()%2001-1000;
			cout<<dane[i]<<endl;
			}
max=dane[0];
min=dane[0];
pozmax=0;
pozmin=0;
	for(i=1;i<n;i++)
	{if(dane[i]>max)
		{max=dane[i];
		pozmax=i;
		}
	if(dane[i]<min)
		{max=dane[i];
		pozmax=i;
		}}
cout<<max<<" na pozycji "<<pozmax<<endl;
cout<<min<<" na pozycji "<<pozmin;
}

