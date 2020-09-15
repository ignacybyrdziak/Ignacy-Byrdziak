#pragma once

#ifndef structures_h
#define structures_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef char* text;

typedef struct edge
{
	text city1;
	text city2;
	int distance;
	struct edge *next;
} Edge;

typedef struct vertex
{
	text city;
	struct vertex *next;
} Vertex;

#endif