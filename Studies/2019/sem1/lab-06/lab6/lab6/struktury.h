#pragma once

#ifndef STRUKTURY_H  
#define STRUKTURY_H

#include <vector> 
#include <string>

std::vector < std::vector<int> > vec;

//for (int i = 0; i < vec.size(); i++)
//{
//	for (int j = 0; j < vec[i].size(); j++)
//	{
//		std::cout << vec[i][j] << " ";
//	}
//	std::cout << std::endl;
//}

struct Wheel {											//lub chyba mo¿e byæ enum
	enum class Type { zimowe, letnie };
};
struct Car {
	Wheel::Type kola[4];
};
struct date {
	int year;
	int month;
	int day;
};

#endif