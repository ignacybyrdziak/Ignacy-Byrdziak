#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{int n,r,i,tr=0;
cout<<" Podaj ilosc punktow ";
cin>>n;
cout<<" Podaj r";
cin>>r;
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
for(i=0;i<n;i++)
	{if( (punkty[i][0]*punkty[i][0])+(punkty[i][1]*punkty[i][1])<=r*r )
		tr++;
	}
cout<<" Do tego okregu naleza "<<tr<<" punkty ";
return 0;
}
