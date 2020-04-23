#include <iostream>
#include <string>
#include <fstream>
 
using std::ifstream;
struct Osoba
{
	int wiek;
	std::string imie;
};

void Powieksz(Osoba** &tablica, int& stary_rozmiar, int nowy_rozmiar)						//od P.Marka
{
	auto temp = new Osoba*[nowy_rozmiar];
	for (int i = 0; i < stary_rozmiar; ++i)
		temp[i] = tablica[i];
	for (int i = stary_rozmiar; i < nowy_rozmiar; ++i)
		temp[i] = nullptr;
	delete[] tablica;
	tablica = temp;
	stary_rozmiar = nowy_rozmiar;
}

void Odczytaj(const std::string& file_name)
{
	ifstream wejscie(file_name);
	if (!wejscie)
	{
		std::cerr << "nie udalo sie otw pliku: " << file_name << "\n";
		return;
	}
	int wiek;
	std::string imie;
	int N = 5;
	//Osoba* tab[5]{};
	Osoba** tab = new Osoba*[N];
	int ile = 0;
	int suma = 0;
	while (wejscie >> imie >> wiek)
	{
		if (ile == N)
		{
			//robimy nowa tablice
			Powieksz(tab, N, N * 3 / 2);
			//auto temp = new Osoba*[3 * N / 2];
			//for (int i = 0; i < N; ++i)
			//	temp[i] = tab[i];
			//for (int i = ile; i < 3 * N / 2; ++i)
			//	temp[i] = nullptr;			
			//delete [] tab;
			//tab = temp;
			//N = 3 * N / 2;
		}
		tab[ile++] = new Osoba{ wiek, imie };
		suma += wiek;
	}

	double srednia = static_cast<double>(suma) / ile;
	for (int i = 0; i < ile; ++i)
		if (tab[i]->wiek < srednia)
			std::cout << tab[i]->imie << "\n";

	int iterator = ile;
	while (iterator)
	{
		delete tab[--iterator];
	}

	//for (auto ptr = tab; ptr < tab + ile; ++ptr)
	//	delete ptr;

	delete[] tab;
}




int main(int argc, char* argv[])
{

	for (int i = 0; i < argc; ++i)
		std::cout << argv[i] << "\n";

	Odczytaj(argv[1]);
}
