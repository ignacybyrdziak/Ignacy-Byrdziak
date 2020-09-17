#pragma once

#ifndef structures_h
#define structures_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef char* text;

typedef struct grafowa
{
	int v;          // numer w�z�a docelowego i waga kraw�dzi
	struct grafowa * next;
	struct zwykla * dol;
} Grafowa;

typedef struct zbiory
{
	bool p;          // numer w�z�a docelowego i waga kraw�dzi
	struct zbiory * next;
} Zbiory;

typedef struct zwykla
{
	int v;          // numer w�z�a docelowego i waga kraw�dzi
	struct zwykla * next;
} Zwykla;

typedef struct slistEl
{
	int v, w;           // numer w�z�a docelowego i waga kraw�dzi
	struct slistEl * next;
} slistEL;

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