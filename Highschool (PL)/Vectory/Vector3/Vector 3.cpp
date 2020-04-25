#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;
int main()
{int i,n;
srand(time(NULL));
cout<<" Podaj n ";
cin>>n;
vector <int> vec;
vector <int> vec2;
vector <int> vec3;
for(i=0;i<n;i++)
	vec.push_back(rand()%21-10);
for(i=0;i<vec.size();i++)
	cout<<vec[i]<<endl;
for(i=0;i<vec.size();)
	{if(vec[i]>0)
		{vec2.push_back(vec[i]);
		vec.erase(vec.begin()+i);
		}
	if(vec[i]<0)
		{vec3.push_back(vec[i]);
		vec.erase(vec.begin()+i);
		}
	if(vec[i]==0)
		i++;	
	}
cout<<" VECTOR "<<endl;
for(i=0;i<vec.size();i++)
	cout<<vec[i]<<endl;
cout<<" VECTOR 2 "<<endl;
for(i=0;i<vec2.size();i++)
	cout<<vec2[i]<<endl;
cout<<" VECTOR 3 "<<endl;
for(i=0;i<vec3.size();i++)
	cout<<vec3[i]<<endl;
cout<<" POSORTOWANY VECTOR "<<endl;
for(i=0;i<vec.size();i++)
	cout<<vec[i]<<endl;
sort(vec2.begin(),vec2.end());
sort(vec3.begin(),vec3.end());
cout<<" POSORTOWANY VECTOR 2"<<endl;
for(i=0;i<vec2.size();i++)
	cout<<vec2[i]<<endl;
cout<<" POSORTOWANY VECTOR 3"<<endl;
for(i=0;i<vec3.size();i++)
	cout<<vec3[i]<<endl;
return 0;
}
