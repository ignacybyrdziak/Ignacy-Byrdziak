#include <iostream>
#include <chrono>
#include <random>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <algorithm>

using namespace std;

void zamiana(int & x, int & y) {
	swap(x, y);
};
void tablos(int tab[], int n) {
	default_random_engine silnik;
	silnik.seed(chrono::system_clock::now().time_since_epoch().count());
	uniform_int_distribution<int> normalny(-10, 10);
	for (int i = 0;i < n;i++) {
		tab[i] = normalny(silnik);
		cout << tab[i] << " ";
	}
};
void potega(int licz, int pot) {
	if (pot == 0) {
		cout << "1";
		return;
	}
	double wynik = licz;
	for (int i = 0;i <abs(pot) - 1;i++) {
		wynik *= licz;
	}
	if (pot < 0) {
		cout << (1 / wynik);
	}
	else {
		cout << wynik;
	}
};
void euklidesowa(int Xa, int Ya, int Xb, int Yb) {
	cout << sqrt((Xa - Xb)*(Xa - Xb) + (Ya - Yb)*(Ya - Yb));
};
void tablica(int tab[], int n) {
	for (int i = 0;i < n;i++) {
		cout << tab[i] << " ";
	}
};
void ostatnie(int tab[], int n) {
	if (n > 0) {
		cout << tab[n - 1] << " ";
		ostatnie(tab, n - 1);
	}
	else
		return;
};
void kwadratowe(int a, int b, int c) {
	double x1, x2, delta, re, im;
	if (a == 0) {
		if (b == 0) {
			if (c == 0) {
				cout << "Tozsamosciowe";
			}
			else
				cout << "Zbior pusty";
		}
		else
			cout << (-1 * c) / b << endl;
	}
	else {
		delta = b * b - 4 * (a*c);
		if (delta == 0) {
			x1 = -1 * b / 2 * a;
			cout << x1 << endl;
		}
		else if (delta > 0) {
			x1 = (-1 * b - sqrt(delta)) / (2 * a);
			x2 = (-1 * b + sqrt(delta)) / (2 * a);
			cout << x1 << " " << x2 << endl;
		}
		else {
			re = (-1 * b) / (2 * a);
			im = (sqrt(-delta)) / (2 * a);
			cout << re << "+" << im << "i" << endl;
		}
	}
};
void uklad(double a1, double a2, double b1, double b2, double c1, double c2) {
	double W, Wx, Wy;
	W = a1 * b2 - a2 * b1;
	Wx = c1 * b2 - c2 * b1;
	Wy = a1 * c2 - a2 * c1;
	if (W == 0) {
		if (Wx == 0 && Wy == 0) {
			cout << " Uklad nieoznaczony " << endl;
		}
		else
			cout << " Uklad sprzeczny " << endl;
	}
	else {
		cout << Wx / W << " " << Wy / W << endl;
	}
};
int fib_rek(int n) {
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else {
		return fib_rek(n - 1) + fib_rek(n - 2);
	}
};
int fib_ite(int n)
{
	int fib1 = 1, fib2 = 1;
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
	{
		for (int i = 0; i < n-2; i++)
		{
			fib1 += fib2;
			cout << fib1 << endl;
			fib2 = fib1 - fib2;
			cout << fib2 << endl;
		}
	}	
	return fib1;
};
void tab_sort(int tab[]) 
{
	for (int j = 0; j < 10; j++) {
		for (int i = j + 1; i < 10; i++) {
			if (tab[i] < tab[j]) {
				swap(tab[j], tab[i]);
			}
		}
	}
};
void hanoi(int ile, char a, char b, char c,int &il) {
	if (ile>0)
	{
		il++;
		hanoi(ile - 1, a, b, c, il);
		hanoi(ile - 1, b, c, a, il);
	}
};
void vec_sort(vector <int> &v)
{
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
};
void vec_wypisz(vector <int> &v)
{
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
};
void vec_losowe(vector<int> &v,int n)
{
	default_random_engine silnik;
	silnik.seed(chrono::system_clock::now().time_since_epoch().count());
	uniform_int_distribution<int> normalny(-10, 10);
	for (int i = 0; i < n; i++) {
		v.push_back(normalny(silnik));
		cout << v[i] << " ";
	}
};
pair<int, int> vec_naj(vector <int> v)
{
	pair<int, int>naj;
	naj.first = *min_element(v.begin(),v.end());
	naj.second = *max_element(v.begin(), v.end());
	return naj;
};

int main() {
	/*
	vector <int> v;																//12a,12b,12d
	int rozm = 5;
	vec_losowe(v, rozm);
	cout << endl;
	vec_sort(v);
	cout << endl;
	vec_wypisz(v);
	cout << endl<<endl;															
	
	pair<int, int>naj;															//12c
	naj = vec_naj(v);
	cout <<" MIN = "<< naj.first << " \n"<< " MAX = " << naj.second << endl;
	
	//pair <int, int> naj;														/PARY!!!!!!!!!!!!!!!!
	//naj.first = 5;
	//naj.second = 7;
	//cout << naj.first<< " " << naj.second << '\n';
	//pair <int, int> naj2;
	//naj2 = make_pair(4, 2);
	//cout << endl;
	//cout << naj2.first << " " << naj2.second << '\n';
	

	int il = 0;																	//11
	char a=97,b=98,c=99;
	hanoi(5,a,b,c,il);
	cout << il;


	const int N = 10;															//9
	int tab[N];
	default_random_engine silnik;
	silnik.seed(chrono::system_clock::now().time_since_epoch().count());
	uniform_int_distribution<int> normalny(-10, 10);
	for (int i = 0; i < N; i++) {
		tab[i] = normalny(silnik);
		cout << tab[i] << " ";
	}
	tab_sort(tab);
	cout << endl;
	for (int i = 0; i < N; i++) {
		cout << tab[i] << " ";
	}

	cout << fib_ite(6);															//7ite
																		
	cout<< fib_rek(6);															//7rek

	int x = 1, y = 2;															//1
	zamiana(x,y);
	cout << x << " " << y;
	
	potega(2,-5);																//3

	const int n = 10;															//2
	int tab[n];
	for (int i = 0;i < n;i++) {
	tab[i] = 0;
	}
	tablos(tab, n);

	euklidesowa(2,-2,3,0);														//4

	const int n = 10;															//5
	int tab[n];
	for (int i = 0;i < n;i++) {
	if (i % 2 == 0) {
	tab[i] = 0;
	}
	else {
	tab[i] = 1;
	}
	}
	tablica(tab, n);

	const int n = 10;															//6
	int tab[n];
	for (int i = 0;i < n;i++) {
	if (i % 2 == 0) {
	tab[i] = 0;
	}
	else {
	tab[i] = 1;
	}
	cout << tab[i] << " ";
	}
	cout << endl;
	ostatnie(tab, n);

	kwadratowe(2, 4, 5);														//10

	uklad(1, 2, 3, 4, 5, 6);													//11

	*/

	return 0;
}