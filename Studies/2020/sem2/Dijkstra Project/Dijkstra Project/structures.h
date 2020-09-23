#pragma once

#ifndef structures_h
#define structures_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef char* text;

// A structure to represent a node in adjacency list 
struct AdjListNode
{
	int dest;
	int weight;
	struct AdjListNode* next;
};

// A structure to represent an adjacency list 
struct AdjList
{
	struct AdjListNode *head;  // pointer to head node of list 
};

// A structure to represent a graph. A graph is an array of adjacency lists. 
// Size of array will be V (number of vertices in graph) 
struct Graph
{
	int V;
	struct AdjList* array;
};

// Structure to represent a min heap node 
struct MinHeapNode
{
	int  v;
	int dist;
};

// Structure to represent a min heap 
struct MinHeap
{
	int size;      // Number of heap nodes present currently 
	int capacity;  // Capacity of min heap 
	int *pos;     // This is needed for decreaseKey() 
	struct MinHeapNode **array;
};

typedef struct edge
{
	text city1;
	text city2;
	int distance;
	struct edge *next;
} Edge;

typedef struct vertex
{
	int counter;
	text city;
	struct vertex *next;
} Vertex;

#endif