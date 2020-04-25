#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{string w,w1;
int x,n;
cin>>w>>w1;
if(w1.size()>w.size())
	swap(w1,w);
if(w.find(w1)!=-1)
	{x=w.find(w1);
	 w.erase(x,w1.size());
	}
cout<<w;

}
