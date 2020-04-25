#include <iostream>
#include <cstring>
using namespace std;
int main()
{int i;
string wyr;
cin>>wyr;
for(i=0;i<wyr.size();)
	{if(wyr[i]=='a'||wyr[i]=='e'||wyr[i]=='i'||wyr[i]=='o'||wyr[i]=='u'||wyr[i]=='y')
		wyr.erase(i,1);
	else
		i++;
	}
cout<<wyr;
return 0;
}
