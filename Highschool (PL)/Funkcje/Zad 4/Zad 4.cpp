#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int sum(int x,int y)
	{int s=0;
	 for(;x<=y;x++)
	 	s+=x;
	return s;
	}
int main()
{srand(time(NULL));
int i,a,b;
for(i=0;i<10;i++)
	{a=rand()%21;
	 b=rand()%21;
	 if(a>b) swap(a,b);
	cout<<" Suma liczb z przedzialu "<<a<<" do "<<b<<" wynosi "<<sum(a,b)<<endl;
	} 
}
