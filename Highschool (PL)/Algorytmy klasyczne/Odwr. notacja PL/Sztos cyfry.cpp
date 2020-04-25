#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int main()
{string d;
int i,n;
cout<<" Podaj ONP "<<endl;
cin>>d;
vector <int> sztos;
for(i=0;i<d.size();i++)
	{if(d[i]>=48 && d[i]<=57)
		sztos.push_back(d[i]);
	 else
	 	{if(sztos.size()<2)
	 		{cout<<" Co je 123 brak liczby "<<endl;
	 		return 1;
			}
		 switch(d[i])
	 		{case '+':sztos.push_back([sztos.size()-2]+sztos[sztos.size()-1]);break;
	 		 case '-':sztos.push_back([sztos.size()-2]-sztos[sztos.size()-1]);break;
	 		 case '*':sztos.push_back([sztos.size()-2]*sztos[sztos.size()-1]);break;
	 		 case '/':sztos.push_back([sztos.size()-2]/sztos[sztos.size()-1]);break;
	 		 default: cout<<" Wybrales zly operator "<<endl;
	 		 		   return 1;
			}
		sztos.erase(sztos.end()-1,sztos.end());	
	 	}
	}
	
}
