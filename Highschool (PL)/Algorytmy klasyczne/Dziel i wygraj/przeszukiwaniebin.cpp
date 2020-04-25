#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	int n,k,x;
	cout << "podaj rozmiar tablicy: ";
	cin >> n;
	srand(time(NULL));
	int tab[n],lewy=0,prawy=n-1;
	for(int i=0;i<n;i++)
		{tab[i]=rand()%101;
		cout << tab[i] << "\t";
		}
	cout << endl;
	sort(tab,tab+n);
	for(int l=0;l<n;l++)
		cout << tab[l] << "\t";	
	cout << endl;
	cout << "podaj szukana wartosc: ";
	cin >> x;
	while(lewy<=prawy)
	{
		k=(lewy+prawy)/2;
		if(tab[k]==x)
		{
			cout << "szukana wartosc jest na pozycji " << k+1;
			return 0;
		}
		else
		{
			if(x>tab[k])
				lewy=k+1;
			else
				prawy=k-1;
		}
	}
	cout << "szukana wartosc nie wystepuje w tablicy";
	return 1;
}
