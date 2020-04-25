#include<iostream>
#include<cmath>
using namespace std;

double funkcja(double x){
	double y;
	y=sin((x/180)*M_PI);
	return y;
};
double pole_obszaru(double a, double b, int n){
	double P=0;
	double d=(b-a)/n;
	double x;
	for (int i=0; i<n; i++){
		x=a+(i*d)+(d/2);
		P=P+d*abs(funkcja(x));
	}
	return P;
};
int main(){
	double a, b;
	int n;
	cout<<"Podaj zakres do obliczenia pola\n";
	cin>>a>>b;
	cout<<"Podaj ilosc prostokatow ";
	cin>>n;
	cout<<"Pole pod wykresem wynosi "<<pole_obszaru(a,b,n);
	return 0;
}
