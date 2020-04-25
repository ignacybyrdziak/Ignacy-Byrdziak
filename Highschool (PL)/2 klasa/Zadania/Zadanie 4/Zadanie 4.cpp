#include <iostream>
using namespace std;
int main()
{int sum=0,sil=1,n;
cout<<" Podaj n ";
cin>>n;
	for(int i=1;i<=n;i++)
		{sil=sil*i;
		sum=sum+sil;
		}
	cout<<" Suma wynosi "<<sum;
return 0;
}
