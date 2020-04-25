#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{ifstream odczyt("anagram.txt");
 ofstream zapisa("odp_4a.txt");
 ofstream zapisb("odp_4b.txt");
 string a,b,c,d,e,a1,b1,c1,d1,e1;
 while(!odczyt.eof())
{odczyt>>a>>b>>c>>d>>e;
a1=a,b1=b,c1=c,d1=d,e1=e;
if(a.size()==b.size() && b.size()==c.size() && c.size()==d.size() && d.size()==e.size())
	{zapisa<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<endl;
	 sort(a.begin(),a.end());
	 sort(b.begin(),b.end());
	 sort(c.begin(),c.end());
	 sort(d.begin(),d.end());
	 sort(e.begin(),e.end());
	 if(a==b && b==c && c==d && d==e)
	 	{zapisb<<a1<<" "<<b1<<" "<<c1<<" "<<d1<<" "<<e1<<" "<<endl;
		}
	}

	
}
 
}
