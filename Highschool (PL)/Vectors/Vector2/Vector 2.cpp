#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{int i,n,k,x;
srand(time(NULL));
cout<<" Podaj n ";
cin>>n;
vector <int> vec;
for(i=0;i<n;i++)
	vec.push_back(rand()%2001-1000);
for(i=0;i<vec.size();i++)
	cout<<vec[i]<<endl;
cout<<" Podaj k elementow do usuniecia ";
cin>>k;
for(i=1;i<=k;i++)
	vec.pop_back();
cout<<" *************** "<<endl;
for(i=0;i<vec.size();i++)
	cout<<vec[i]<<endl;
for(i=0;i<vec.size();i++)
	if(vec[i]<0)
		{vec.erase(vec.begin()+i);
		 vec.insert(vec.begin()+i,0);
		}
cout<<" *************** "<<endl;
for(i=0;i<vec.size();i++)
	cout<<vec[i]<<endl;
cout<<" *************** "<<endl;
vec.clear();
for(i=0;i<vec.size();i++)
	cout<<vec[i]<<endl;
return 0;
}
	
