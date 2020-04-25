#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{int n,i;
srand(time(NULL));
cout<<" Podaj ilosc liczb ";
cin>>n;
int dane [n];
	for(i=0;i<n;i++)
		{dane[i]=rand()%2001-1000;
		cout<<dane[i]<<endl;
		}
return 0;
}
