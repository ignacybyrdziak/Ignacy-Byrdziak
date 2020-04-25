#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
int main()
	{
		int i,k,il=1;
		string w1;
		vector <char> w2;
		cout<<" Podaj tekst: "<<endl;
		cin>>w1;
		for(i=0;i<w1.size();i++)
			{
				if(w1[i]==w1[i+1])
					{
						il++;
					}
				else
					{
						w2.push_back(il+48);
						w2.push_back(w1[i]);
						il=1;
					}
			}		
		cout<<" Zaszyfrowany: ";
		for(i=0;i<w2.size();i++)
			cout<<w2[i];
		return 0;			
	}
