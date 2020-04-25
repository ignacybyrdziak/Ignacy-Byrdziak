#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{int k,n,i;
vector <int> tab;
cout<<" Podaj k "<<endl;
cin>>k;
cout<<" Podaj n "<<endl;
cin>>n;
tab.push_back(1);
for(i=1;i<=n;i++)
	tab.push_back(pow(k,i));
for(i=0;i<tab.size();i++)
	cout<<tab[i]<<endl;;
return 0;
}
