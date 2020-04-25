#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int main()
{
	string onp;
	vector <int> stos;
	int pom,a,b;
	cout << "podaj dzialanie w ONP: ";
	cin >> onp; 
	for(int i=0;i<onp.length();i++) // przejezdzamy przez stringa
	{
		if(onp[i]>=48 and onp[i]<=57)
			stos.push_back(onp[i]-48); // wrzucanie liczb na stos
		a=stos[stos.size()-2];
		b=stos[stos.size()-1];
		if(onp[i]==42 or onp[i]==43 or onp[i]==45 or onp[i]==47) // *+-/
		{
			if(stos.size()<2) // Blad I
			{
				cout << "Blad - brak liczb na stosie";
				return 1;
			}
			if(onp[i]==42)
			{
				pom=a*b;
				stos.erase(stos.end()-2, stos.end());
				stos.push_back(pom);
			}
			if(onp[i]==43)
			{
				pom=a+b;
				stos.erase(stos.end()-2, stos.end());
				stos.push_back(pom);
			}
			if(onp[i]==45)
			{
				pom=a-b;
				stos.erase(stos.end()-2, stos.end());
				stos.push_back(pom);
			}
			if(onp[i]==47)
			{
				if(b==0)
				{
					cout << "Blad - proba dzielenia przez 0  ";
					return ;
				}
				pom=a/b;
				stos.erase(stos.end()-2, stos.end());
				stos.push_back(pom);
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
