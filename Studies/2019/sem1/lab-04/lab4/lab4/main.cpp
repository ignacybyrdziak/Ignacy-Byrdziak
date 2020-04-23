#include <iostream>
#include <cmath>
#include <random>
#include <chrono>
using namespace std;
 
int main() {
	/*	
	const int N=10;
	int tab[N],min;																//zad1
	default_random_engine silnik;
	silnik.seed(chrono::system_clock::now().time_since_epoch().count());
	uniform_int_distribution<int> normalny(-10, 10);
	for (int i = 0;i < N;i++) {
		tab[i] = normalny(silnik);
		cout << tab[i] << " ";
	}
	cout << endl;
	for (int j = 0;j < 10;j++) {
		for (int i = j+1;i < 10;i++) {
			if (tab[i] < tab[j]) {
				swap(tab[j], tab[i]);
			}
		}
	}
	cout << endl;
	for (int i = 0;i < N;i++) {
		cout << tab[i] << " ";
	}
	cout << endl;
	const int N=5,M=6
	int tab1[N][M], tab2[M][N];													//zad2
	default_random_engine silnik;
	silnik.seed(chrono::system_clock::now().time_since_epoch().count());
	uniform_int_distribution<int> normalny(-10, 10);
	for (int j = 0; j < N;j++) {
		for (int i = 0;i < M;i++) {
			tab1[j][i] = normalny(silnik);
			cout << tab1[j][i] <<"\t";
		}
		cout << endl<<endl;
	}
	cout << " *************** " << endl;
	for (int j = 0; j < M;j++) {
		for (int i = 0;i < N;i++) {
			tab2[j][i] = tab1[i][j];
			cout << tab2[j][i] << "\t";
		}
		cout << endl << endl;
	}
	*/
	const int N = 6;															//zad3
	int tab[N][N];
	int il = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			tab[i][j] = 0;
		}
	}
	for (int i = 0;i < N;i++) {
		for (int j = i;j < N - i;j++) {
			tab[i][j] = il;
			il++;
		}
		for (int k = i+1; k < N - i; k++) {
			tab[k][N-i-1] = il;
			il++;
		}
		for (int l = N - i - 2; l > i; l--) {
			tab[N - i-1][l] = il;
			il++;
		}
		for (int m = N - i - 1; m > i; m--) {
			tab[m][i] = il;
			il++;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << tab[i][j] << "\t";
		}
		cout << endl<<endl;
	}
	return 0;
}
