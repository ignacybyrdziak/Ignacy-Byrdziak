#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{int n,a,b,i,nad=0,pod=0;
float wynik;
cout<<" Podaj ilosc punktow ";
cin>>n;
cout<<" Podaj a i b ";
cin>>a>>b;
int punkty [n][2];
srand(time(NULL));
for(i=0;i<n;i++)
	{punkty[i][0]=rand()%6-5;
	punkty[i][1]=rand()%6-5;
	}
cout<<"x\t\ty"<<endl;
for(i=0;i<n;i++)
	{cout<<punkty[i][0]<<"\t\t"<<punkty[i][1]<<endl;
	}
for(i=0;i<n;i++)
	{if(punkty[i][0]*a+b>punkty[i][1])
		nad++;
	if(punkty[i][0]*a+b<punkty[i][1])
		pod++;
	}
cout<<" Prosta y="<<a<<"*x+"<<b;
cout<<" Nad prosta jest "<<nad<<endl;
cout<<" Pod prosta jest "<<pod<<endl;
cout<<" Na prostej jest "<<n-(nad+pod)<<endl;
}


