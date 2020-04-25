#include <iostream>
#include <cstring>
using namespace std;
int main()
{string w;
int i,x;
getline(cin,w);
for(i=0;i<w.size();i++)
	{if(w[i]==' ')
	 	{w.erase(i,1);
	 	i--;
	 	}
	}
cout<<w;
}
