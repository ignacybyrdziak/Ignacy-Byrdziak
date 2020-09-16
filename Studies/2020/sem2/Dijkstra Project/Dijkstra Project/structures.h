#pragma once

#ifndef structures_h
#define structures_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef char* text;

typedef struct vertex
{
	text city1;
	text city2;
	int distance;
	struct vertex *next;
} Vertex;

typedef struct edge
{
	text city;
	struct edge *next;
} Edge;

#endif