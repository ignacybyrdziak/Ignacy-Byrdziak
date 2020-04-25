#include <iostream>
#include <fstream>
using namespace std;
int main()
{ifstream odczyt("towary.txt");
 ofstream zapis("najlepszy_plecak.txt");
string nazwa[10];
float produkty[10][5];
float plecaka,s=0;
bool babel=true;;
int i=0,p=0,x=10; 
for(i=0;i<10;i++)
	produkty[i][4]=0;
for(i=0;!odczyt.eof();i++)
 	{odczyt>>nazwa[i]>>produkty[i][0]>>produkty[i][1]>>produkty[i][2];
 	 produkty[i][3]=produkty[i][0]/produkty[i][1];
 	}
while(babel)
	 {babel=false;
	  int k=x-1;
	  for(int j=0;j<k;j++)
		 {if(produkty[j][3]<produkty[j+1][3])
		 	{swap( produkty[j][3], produkty[j+1][3] );
             swap( produkty[j][2], produkty[j+1][2] );
             swap( produkty[j][1], produkty[j+1][1] );
             swap( produkty[j][0], produkty[j+1][0] );
             swap( nazwa[j], nazwa[j+1] );
		 	 babel=true;
			}
		}
	 }
    
cout<<" Jaka jest obj plecaka? "<<endl;
cin>>plecaka;
 while(plecaka>0)
	 {if(p==10)
	 	break;
	 if(produkty[p][2]==0 || plecaka-produkty[p][1]<0)
	 	{produkty[p][3]=0;
	 	p++;
	 	continue;
		}
	 plecaka-=produkty[p][1];
	 produkty[p][4]++;
	 produkty[p][2]--;
 	 }
 	for(i=0;i<10;i++)
 		{if(produkty[i][4]!=0)
 			{cout<<nazwa[i]<<" "<<produkty[i][4]<<endl;
 			 s+=produkty[i][4]*produkty[i][0];
			}
		}
	cout<<s<<endl;
	cout<<"Pozostale miejsce: "<<plecaka<<endl;
}
