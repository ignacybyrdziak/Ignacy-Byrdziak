#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{int n,a,r,i,tr=0;
float wynik;
cout<<" Podaj ilosc punktow ";
cin>>n;
cout<<" Podaj bok kwadratu";
cin>>a;
int punkty [n][2];
srand(time(NULL));
r=a/2;
for(i=0;i<n;i++)
	{punkty[i][0]=rand()%(a+1)-(a/2);
	punkty[i][1]=rand()%(a+1)-(a/2);
	}
cout<<"x\t\ty"<<endl;
for(i=0;i<n;i++)
	{cout<<punkty[i][0]<<"\t\t"<<punkty[i][1]<<endl;
	}
for(i=0;i<n;i++)
	{if( (punkty[i][0]*punkty[i][0])+(punkty[i][1]*punkty[i][1])<=r*r)
		tr++;
	}
cout<<" Do tego okregu naleza "<<tr<<" punkty ";
wynik=(float)4*tr/n;
cout<<" Pi wynosi oko³o "<<(float)4*tr/n;
return 0;
}
