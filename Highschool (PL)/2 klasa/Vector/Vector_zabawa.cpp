#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;
int main()
{int n,s=0,i,x;
vector <int> nazwa;
cin>>n;
for(i=0;i<n;i++)
	{x=rand()%1001;
	 nazwa.insert(nazwa.begin()+i,x);
	 cout<<i<<".  "<<nazwa[i]<<endl;
	 s+=nazwa[i];
	}
cout<<s<<endl;
cout<<nazwa.size();
i=0;
vector <char> nar;
nar.insert(nar.begin()+i,'P');
Sleep(1000);
cout<<nar[i];
i++;
nar.insert(nar.begin()+i,'a');
Sleep(1000);
cout<<nar[i];
i++;
nar.insert(nar.begin()+i,'b');
Sleep(1000);
cout<<nar[i];
i++;
nar.insert(nar.begin()+i,'l');
Sleep(1000);
cout<<nar[i];
i++;
nar.insert(nar.begin()+i,'o');
Sleep(1000);
cout<<nar[i];
i++;
return 0;
}
