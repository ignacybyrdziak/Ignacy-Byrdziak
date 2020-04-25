#include <iostream>
using namespace std;
int main()
{int i=1,k,n;
double banknot,cena,zapl;
double nomin[15][2];
nomin[0][0]=500;
nomin[1][0]=200;
nomin[2][0]=100;
nomin[3][0]=50;
nomin[4][0]=20;
nomin[5][0]=10;
nomin[6][0]=5;
nomin[7][0]=2;
nomin[8][0]=1;
nomin[9][0]=0.5;
nomin[10][0]=0.2;
nomin[11][0]=0.1;
nomin[12][0]=0.05;
nomin[13][0]=0.02;
nomin[14][0]=0.01;
for(i=0;i<15;i++)
	nomin[i][1]=0;
cout<<" Podaj CENE "<<endl;
cin>>cena;
cout<<" Podaj kwotê "<<endl;
cin>>banknot;
cout<<" ****Kasa**** "<<endl;
zapl=banknot-cena;
while(zapl>0)
	{if(zapl<nomin[i][0])
	 	{i++;
	 	 continue;
		}
	cout<<i;
	if(zapl>=nomin[i][0])
		{zapl-=nomin[i][0];
		 nomin[i][1]++;
		 cout<<" ****Kk**** "<<endl;
		}
	}
for(i=0;i<15;i++)
	{cout<<nomin[i][1]<<" x "<<nomin[i][0]<<endl;
	}
}
