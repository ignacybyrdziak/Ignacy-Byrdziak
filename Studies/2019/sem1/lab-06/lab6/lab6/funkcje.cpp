#pragma once

#include <iostream>
#include <vector>
#include <climits>
#include <random>
#include <chrono>
#include <string>
#include <cmath>

#define debug(x)  std::cerr << "(" << __LINE__ << ") " << #x << " == " << (x) << std::endl
#include "funkcje.h"

//std::vector<std::vector<int>> dodvec(std::vector<std::vector<int>> v1, std::vector<std::vector<int>> v2)
//{
//	for (int i = 0; i < vec.size(); i++)
//	{
//		for (int j = 0; j < vec[i].size(); j++)
//		{
//			std::cout << vec[i][j] << " ";
//		}
//		std::cout << std::endl;
//		return v1;
//	}
//}

bool CheckCar(Car car)
{
	bool ok = true;
	for (int i = 1; i < 4; i++)
	{
		if (car.kola[0] != car.kola[i])
			ok = false;
	}
	std::cout << ok;
	return ok;

}

void SetCar(Car &car, Wheel::Type typ)
{
	for (int i = 0; i < 4; i++)
	{
		car.kola[i] = typ;
		std::cout << 11 << " ";
	}
}

bool przestepny(date data)
{
	if (data.year % 4 == 0)
		return true;
	else
		return false;
}

bool CheckDate(date data)
{
	if (data.month > 12 || data.month < 1)
		return false;
	else if (data.month == 4 || data.month == 6 || data.month == 9 || data.month == 11)
	{
		if (data.day > 30 || data.day < 1)			// dla miesiêcy 30-dniowych
			return false;
	}
	else if (data.month == 2) {
		if (przestepny(data))
		{
			if (data.day > 29 || data.day < 1)		// dla lutego przêstêpnego
				return false;

		}
		else {
			if (data.day > 28 || data.day < 1)		// dla lutego nieprzêstêpnego
				return false;
		}
	}
	else if (data.day > 31 || data.day < 1)			// dla miesiêcy 31-dniowych
		return false;
	return true;
}

date maxdate(date data1, date data2)
{
	if (data1.year > data2.year)					// porównanie lat
		return data1;
	else if (data1.year < data2.year)
		return data2;
	else if (data1.month > data2.month)				// porównanie miesiêcy
		return data1;
	else if (data1.month < data2.month)
		return data2;
	else if (data1.day > data2.day)					// porównanie dni
		return data1;
	else if (data1.day < data2.day)
		return data2;
	else
		return { 0,0,0 };							// jeœli daty s¹ równe
}