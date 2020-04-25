#include <iostream>
#include <cstring>
using namespace std;
int main()
{int i;
string wyr,wyr1;
cin>>wyr>>wyr1;
for(i=0;i<wyr.size();i++)
	{if(wyr[i]=='a'||wyr[i]=='e'||wyr[i]=='i'||wyr[i]=='o'||wyr[i]=='u'||wyr[i]=='y')
		{wyr.insert(i+1,wyr1);
		i+=wyr1.size();
		}
	}
cout<<wyr;
return 0;
}
