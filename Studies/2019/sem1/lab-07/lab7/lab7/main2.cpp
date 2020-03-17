// Powtórka ze strumieni


//#include <fstream>
//#include <iostream>
//#include <sstream>
//#include <string>
//#include <string.h>
//#include <iomanip>
//#include <ios>
//
//int main() {
//	std::stringstream ss;
//	std::ifstream odczyt("plik_wejœciowy.txt");
//	std::ofstream zapis("plik_wejœciowy.txt");
//
//	if (zapis) {
//		for (int i = 0; i <= 20; i++) {
//			zapis << std::setw(10) << i << std::endl;
//		}
//		zapis.close();
//	}
//	if (odczyt) {
//		int n;
//		while (odczyt >> n)
//			std::cout << n << std::endl;
//		odczyt.close();
//	}
//	if (odczyt) {
//		int n;
//		while (!odczyt.eof()) {
//			odczyt >> n;
//			std::cout << n << std::endl;
//		}
//		odczyt.close();
//	}
//	std::string napis = { "Agusia, kocham Cie <3" };
//	for (auto element : napis) {
//		std::cout << element;
//	}
//	std::cout << std::endl;
//	for (int i = 0; i < napis.size(); i++) {
//		std::cout << napis[i];
//	}
//	std::cout << std::endl;
//	double liczba = 10;
//	std::cout << napis << std::endl;
//	ss << liczba;
//	std::string napis2;
//	ss >> napis2;
//	std::cout << napis2;
//	std::cout << std::endl;
//	ss.clear();
//	ss << napis;
//	char c;
//	ss >> c;
//	std::cout << c << std::endl;
//	ss.clear();
//	ss << napis;
//	int liczba2;
//	ss >> liczba2;
//	liczba2 -= 48;
//	// std::cout << liczba2; // nie zadzia³a
//	int liczba3 = c;
//	std::cout << liczba3 << std::endl;
//	int liczba4 = 97;
//	char napis3 = liczba4;
//	std::cout << napis3;
//}