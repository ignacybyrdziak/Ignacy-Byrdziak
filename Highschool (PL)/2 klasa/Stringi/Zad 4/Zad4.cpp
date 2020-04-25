#include <iostream>
#include <cstring>
using namespace std;
int main()
{string w;
int x,n;
cin>>w;
while(w.find("ka")!=-1)
	{x=w.find("ka");
	w.replace(x,2,"bo");
	}
cout<<w;
}
