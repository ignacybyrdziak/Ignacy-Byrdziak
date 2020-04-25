#include <iostream>
using namespace std;
int main ()
{float i=0,SR=0,x,SUM=0;
		do
			{cout<<" Podaj x ";
			cin>>x;
				{SUM=SUM+x;
				i++;
				SR=SUM/i;}
			}
while(x!=0);
	if(i==1)
		{cout<<" Brak sumy i sredniej ";}
	else
		{cout<<" Suma= "<<SUM<<" Srednia= "<<SR<<endl;}
	
return 0;
}




