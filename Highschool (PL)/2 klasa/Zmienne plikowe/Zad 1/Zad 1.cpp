#include <iostream>
#include <fstream>
#include<cstdlib>
#include <ctime>
using namespace std;
int main()
{int x,i;
srand(time(NULL));
ofstream zapis ("dane.txt");
for(i=1;i<40;i++)
	{x=rand()%1001;
	 zapis<<x<<endl;
	}
x=rand()%1001;
zapis<<x;
return 0;
}
