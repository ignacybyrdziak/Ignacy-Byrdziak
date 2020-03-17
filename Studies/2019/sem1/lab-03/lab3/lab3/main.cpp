#include <iostream>
#include <cmath>
#include <random>
#include <chrono>
#include <vector>
using namespace std;

void kolejne(int n) {
	for (int i = 1; i <= n; i++) {
		cout << i << endl;
	}
};
void odwrotne(int n) {
	for (int i = n; i > 0; i--) {
		cout << i << endl;
	}
};
void dzielnik(int a, int b, int dziel) {
	for (a; a < b; a++) {
		if (a%dziel == 0) {
			cout << a << endl;
		}
	}
};
void wykladnik(int a, int n) {
	int p = a;
	for (int i = 1;; i++) {
		if (i == n) {
			break;
		}
		else
			p *= a;
	}
	cout << p;
};
int pierwsza(int liczba) {
	for (int i = 2; i < sqrt(liczba); i++) {
		if (liczba%i == 0) {
			cout << " Nie pierwsza ";
			return 0;
		}
		else
			continue;
	}
	cout << " Pierwsza ";
	return 0;
};
void losowe(int m, int normalny, int o) {
	int a;
	if (o < 11) {
		if (m == normalny) {
			cout << " Zgadles! " << endl;
		}
		else {
			cout << " Sprobuj jeszcze raz " << endl;
			cin >> a;
			losowe(a, normalny, o + 1);
		}
	}
	else {
		cout << " Za duzo prob " << endl;
	}
};

int main() {
	int a, b, m, n1, n2, dziel, licz, wykl, liczba, kol, sred, sum = 0, min, max, odch = 0;
	string slowo;

	/*	cout << " Podaj liczbe" << endl;																		//1a
		cin >> n1;
		kolejne(n1);

		cout << " Podaj liczbe" << endl;																		//1b
		cin >> n2;
		odwrotne(n2);

		cout << " Podaj liczbe i wykladnik" << endl;															//1c
		cin >> licz >> wykl;
		wykladnik(licz, wykl);

		cout << "Podaj 2 liczby i dzielnik" << endl;															//1d
		cin >> a >> b >> dziel;
		dzielnik(a, b, dziel);

		cout << " Podaj liczbe" << endl;																		//2
		cin >> liczba;
		pierwsza(liczba);

		cout << " Zgadnij liczbe " << endl;																		//3
		cin >> m;
		default_random_engine silnik;
		silnik.seed(chrono::system_clock::now().time_since_epoch().count());
		uniform_int_distribution<int> normalny(-10, 10);
		losowe(m, normalny(silnik),1);

		do{																										//4
			cout<<" Kolejna liczba? Wpisz \"Tak\" "<<endl;
			cin>>slowo;
			vector<int>kaczka;
			if(slowo=="Tak"){
				cout<<" Podaj liczbe "<<endl;
				cin>>kol;
				kaczka.push_back(kol);
				min=kaczka[0];
				max=kaczka[0];
				cout<<"Ilosc liczb: "<<kaczka.size();
				for(int i=0;i<kaczka.size()-1;i++){
					sum+=kaczka[0];
					if(kaczka[0]>max){
						max=kaczka[0];
					}
					if(kaczka[0]<min){
						min=kaczka[0];
					}
				}
				sred=sum/kaczka.size();
				cout<<" Srednia: "<<sred<<" Max: "<<max<<" Min: "<<min<<" Odchylenie "<<odch<<endl;
			}
			else
				break;
		}
		while(slowo=="Tak");
	*/		
	
	int hor[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 }, wer[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
	cout << " ";
	for (int i = 0; i < 15; i++) {
		cout << hex << hor[i] << " ";
	}
	cout << endl << " ******************************* " << endl;
	for (int i = 0; i < 15; i++) {
		cout << hex << wer[i] << " ";
		for (int k = 0; k < 15; k++) {
			cout << hex << wer[i] * hor[k] << " ";
		}
		cout << endl;
	}
	return 0;
}