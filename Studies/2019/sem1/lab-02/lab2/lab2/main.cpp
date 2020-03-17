#include <iostream>
#include <cmath>
using namespace std;

double dzialanie(double a, char c, double b) {
	switch (c) {
	case '+': {
		return a + b;
	}
	case '-': {
		return a - b;
	}
	case '*': {
		return a * b;
	}
	case '/': {
		if (b == 0) {
			cout << "Blad" << endl;
			break;
		}
		return a / b;
	}
			  /*	case'%': {
					  if (b == 0) {
						  cout << "Blad" << endl;
					  //	break;
					  }
				  return a % b;
				  }


		  	*/
	}
	return 0;
};
int sale(int pojemnosc, int ilosc) {
	if (ilosc%pojemnosc == 0) {
		return ilosc / pojemnosc;
	}
	else
		return ((ilosc / pojemnosc) + 1);
};
char blizej(double xa, double ya, double xp, double yp, double xo, double yo) {
	double odl1, odl2;
	odl1 = sqrt((xa - xp)*(xa - xp) + (ya - yp)*(ya - yp));
	odl2 = sqrt((xa - xo)*(xa - xo) + (ya - yo)*(ya - yo));
	if (odl1 > odl2)
		return 'O';
	else
		return 'P';
};

int main() {
	double a1, a2, b1, b2, c1, c2, W, Wx, Wy;
	cout << " Podaj a1,a2,b1,b2,c1,c2" << endl;
	cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;
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
		cout << Wx / W << " "<< Wy / W <<endl;
	}
	return 0;
}
/*
int main() {
	double xa, ya, xp, yp, xo, yo;
	cout << " Podaj xa,ya,xp,yp,xo,yo"<<endl;
	cin >> xa >> ya >> xp >> yp >> xo >> yo;
	cout << blizej(xa, ya, xp, yp, xo, yo);
	return 0;
int main() {
	double a, b;
	char c;
	cout << "Podaj liczbe, dzialanie i liczbe" << endl;
	cin >> a >> c >> b;
	cout << dzialanie(a, c, b) << endl;
	return 0;
}

int main() {
	int pojemnosc, ilosc;
	cout << "Podaj pojemnosc sale i liczbe osob" << endl;
	cin >> pojemnosc >> ilosc;
	cout << sale(pojemnosc, ilosc) << endl;
	return 0;
}
int main() {
	int a, b, c;
	cout << "Podaj a,b,c" << endl;
	cin >> a >> b >> c;
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
	return 0;
}
*/
