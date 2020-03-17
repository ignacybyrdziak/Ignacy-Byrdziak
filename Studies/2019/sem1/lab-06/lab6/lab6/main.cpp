#pragma once
#define debug(x)  std::cerr << "(" << __LINE__ << ") " << #x << " == " << (x) << std::endl

// biblioteki standardowe
#include <iostream>
#include <vector> 
#include <string>   

// wlasne pliki
#include "struktury.h"
#include "funkcje.h"


int main() {

	//Car wisla;
	//wisla.kola[1] = Wheel::Type::zimowe;
	//wisla.kola[2] = Wheel::Type::zimowe;
	//wisla.kola[3] = Wheel::Type::zimowe;
	//wisla.kola[4] = Wheel::Type::zimowe;

	//if (!CheckCar(wisla))
	//	SetCar(wisla, Wheel::Type::letnie);

	Car odra
	{ 
		{Wheel::Type::zimowe, Wheel::Type::zimowe, Wheel::Type::zimowe, Wheel::Type::letnie}
	};

	if (!CheckCar(odra))
		SetCar(odra, Wheel::Type::letnie);

	date data1{ 2017,7,15 };
	date data2{ 2016,12,31 };

	return 0;
}