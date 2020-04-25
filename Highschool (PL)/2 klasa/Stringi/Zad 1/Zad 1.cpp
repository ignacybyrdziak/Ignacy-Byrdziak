#include <cstring>
#include <iostream>
using namespace std;
int main()
{int i,j;
string w;
cin>>w;
for(i=0,j=1;i<w.size();)
	{if(w[i]==w[i+1]) 
		{w.erase(i+1,1);
		}
	else
		i++;
	}
cout<<w;
return 0;
}
