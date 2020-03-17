#include <iostream>
#include <string>

using namespace std;


template <typename end>
struct endlist
{
	end zmienna;
};


int main()
{
	// deklarujesz ze zmienna to bedzie int.
	endlist<double> strINT1;
	strINT1.zmienna = 58;
	cout << endl << strINT1.zmienna << endl;

	// albo string.
	endlist<string> strSTRING;
	strSTRING.zmienna = "napis";
	cout << endl << strSTRING.zmienna << endl;

	// albo lista list<int>
	endlist<endlist<double>> WeNeedToGoDeeper;
	WeNeedToGoDeeper.zmienna = strINT1;

	cout << WeNeedToGoDeeper.zmienna.zmienna << endl;

	// albo lista list list<int>
	endlist<endlist<endlist<double>>> EvenDeeper;

	EvenDeeper.zmienna = WeNeedToGoDeeper;

	cout << EvenDeeper.zmienna.zmienna.zmienna << endl;
	return 0;
}