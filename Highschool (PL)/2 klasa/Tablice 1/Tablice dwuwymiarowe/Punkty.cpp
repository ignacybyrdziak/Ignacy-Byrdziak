#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{int n,i;
cout<<" Podaj ilosc punktow ";
cin>>n;
int punkty [n][2];
srand(time(NULL));
for(i=0;i<n;i++)
	{punkty[i][0]=rand()%41-20;
	punkty[i][1]=rand()%41-20;
	}
cout<<"x\t\ty"<<endl;
for(i=0;i<n;i++)
	{cout<<punkty[i][0]<<"\t\t"<<punkty[i][1]<<endl;
	}
return 0;
}
