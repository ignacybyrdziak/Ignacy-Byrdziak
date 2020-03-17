#pragma once

#ifndef FUNKCJE_H  // jeżeli FUNKCJE_H jest niezdefiniowane ...
// jeżeli FUNKCJE_H jest zdefiniowane, to przeskakujemy od razu do #endif 
#define FUNKCJE_H  // ... to zdefiniuj FUNKCJE_H

#include <vector> 
#include <string>

// dołączam deklaracje struktur z pliku struktury.h
#include "struktury.h"

bool CheckCar(Car car);

void SetCar(Car &car, Wheel::Type typ);

bool CheckDate();

date maxdate();

#endif