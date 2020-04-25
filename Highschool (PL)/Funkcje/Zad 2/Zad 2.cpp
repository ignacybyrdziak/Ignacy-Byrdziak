#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int nwd(int l1,int l2)
{while(l1!=0 && l2!=0)
	{if(l1>l2)
		l1=l1%l2;
	else
		l2=l2%l1;
	}
return l1+l2;
};
int nww (int l1,int l2)
{return l1*l2/nwd(l1,l2);
};
int main()
{int i,x,y;
srand(time(NULL));
for(i=1;i<=10;i++)
	{x=rand()%1000+1;
	 y=rand()%1000+1;
	 cout<<x<<" "<<y<<" NWD wynosi "<<nwd(x,y)<<endl; 
	 cout<<x<<" "<<y<<" NWW wynosi "<<nww(x,y)<<endl;
	}
}
	
