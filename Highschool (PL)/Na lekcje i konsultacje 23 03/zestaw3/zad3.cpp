#include <iostream>
#include <fstream>
using namespace std;
int main(){
	ifstream odczyt("dane.txt");
	ofstream zapis("odp.txt");
	double tab[7][20];
	for(int i=0;i<20;i++){	
		for(int j=0;j<7;j++){
			odczyt>>tab[j][i];
		}
	}
 int tabw[6][20];
	for(int i=0;i<20;i++){			
		int mian[6];
		for(int k=0;k<6;k++){
			mian[k]=1;
		}
		for(int m=0;m<tab[6][i];m++){
		int pozmax=0;
		float max=tab[0][i]/mian[0];
			for(int j=1;j<6;j++){				//szukanie Str¹ga
				if(tab[j][i]/mian[j]>max){
					max=tab[j][i];
					pozmax=j;
				}
			}	
		mian[pozmax]++;
		}
		for(int m=0;m<6;m++){
			tabw[m][i]=mian[m]-1;
			cout<<tabw[m][i]<<" ";
		}
		cout<<endl;
	}	
	return 0;
}
