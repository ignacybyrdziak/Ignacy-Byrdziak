#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>
using namespace std;
int main()
	{string onp, w;
	cout<< " Podaj wyraz w ONP "<<endl;
	getline(cin,onp);
	stringstream ss;
	vector <float> stos;
	int i, a, b, pom, liczba;
	w="";
	for(i=0;i<onp.size();i++)
		{if(onp[i]>=48 and onp[i]<=57)
			{w=w+onp[i];
			cout<<w<<endl;
			}
		else
			{if(onp[i]==32)
				{ss<<w;
				ss>>liczba;
				stos.push_back(liczba);
				cout<<liczba<<endl;
				ss.clear();
				w="";
				}
			else
			 if(onp[i]==42 or onp[i]==43 or onp[i]==45 or onp[i]==47)	
			 	{a=stos[stos.size()-2];
		 	 	 b=stos[stos.size()-1];
				 if(stos.size()<2)
					{cout << "Blad - brak liczb na stosie";
					 return 1;
					}
				if(onp[i]==42)
					{pom=a*b;
					stos.erase(stos.end()-2, stos.end());
					stos.push_back(pom);
					}
				if(onp[i]==43)
					{pom=a+b;
					stos.erase(stos.end()-2, stos.end());
					stos.push_back(pom);
					}
				if(onp[i]==45)
					{pom=a-b;
					stos.erase(stos.end()-2, stos.end());
					stos.push_back(pom);
					}
				if(onp[i]==47)
					{if(b==0)
						{cout << "Blad - proba dzielenia przez 0  ";
						return 1;
						}
					pom=a/b;
					stos.erase(stos.end()-2, stos.end());
					stos.push_back(pom);
					}
				}
			}
		}
if(stos.size()!=1)
	{
		cout << "Blad - wiecej niz 1 wartosc na stosie";
		return 1;	
	}
	cout << "otrzymana wartosc: " << stos[0];
	return 0;
}
