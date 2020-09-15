#pragma once

#ifndef functions_h
#define functions_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "structures.h"

Edge * Add_New_Distance(text city_1, text city_2, int dist, Edge *head);

Vertex * Add_New_City(text city_1, Vertex *head);

#endif