#pragma once

#ifndef functions_h
#define functions_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "structures.h"

void Printing_City_On_Called_Position(int position, Edge *head);

void Printing_Distance_On_Called_Position(int position, Vertex *head);

bool Finding_Duplicate_Distances(text city_1, text city_2, Vertex *head);

bool Finding_Duplicate_Cities(text city_1, Edge *head);

Vertex * Add_New_Distance(text city_1, text city_2, int dist, Vertex *head);

Edge * Add_New_City(text city_1, Edge *head);

#endif