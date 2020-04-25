#include <iostream>
#include <conio.h>
#include <cstring>
using namespace std;
struct koszykarze 
{ string imie;
  string nazwisko;
  int rok;
  double wzrost;
  double waga }; 
koszykarze dodaj() 
{	dane;
	cout <<"Podaj marke imie: "<<endl;
	cin  >>dane.imie;
	cout <<"Podaj nazwisko: "<<endl;
	cin  >>dane.nazwisko;
	cout
	cout <<"Podaj rok urodzenia: "<<endl;
	cin  >>dane.rok;
	cout <<"Podaj wzrost: "<<endl;
	cin  >>dane.wzrost;
	cout <<"Podaj waga: "<<endl;
	cin  >>dane.waga;
	system("cls");
	return dane; } 
int main() 
{	vector <auta> samochod;
	int k;
	int n=0;
	char wybor, lit; 
	do {system("cls");
		cout<<"Wybierz operacje:"<<endl<<
		<<"1 - dopisz zawodnika"<<endl<<
		<<"# - dopisz zawodnika na wybrane miejsce "<<endl<<
		<<"2 - wyswietl liste "<<endl<<
		<<"3 - zapisz do pliku "<<endl<<
		<<"4 - wczytaj z pliku "<<endl<<
		<<"5 - szukaj po pierwszej literze nazwiska "<<endl<<
		<<"6 - szukaj po pierwszej literze imienia"<<endl<<
		<<"7 - szukaj po roku urodzenia "<<endl<<
		<<
