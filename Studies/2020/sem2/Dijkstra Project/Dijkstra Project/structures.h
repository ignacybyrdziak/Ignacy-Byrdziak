#pragma once

#ifndef structures_h
#define structures_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/// A type definition to fasten char* into "string" in type of 'Text'
typedef char* Text;

/// A structure to represent a node in adjacency list 
struct AdjListNode
{
	int dest;
	int weight;
	struct AdjListNode* next;
};

/// A structure to represent an adjacency list 
struct AdjList
{
	struct AdjListNode *head;  /// pointer to head node of list 
};

/// A structure to represent a graph. A graph is an array of adjacency lists. Size of array will be V (number of vertices in graph) 
struct Graph
{
	int V;
	struct AdjList* array;
};

/// Structure to represent a min heap node 
struct MinHeapNode
{
	int  v;
	int dist;
};

/// Structure to represent a min heap 
struct MinHeap
{
	int size;      /// Number of heap nodes present currently 
	int capacity;  /// Capacity of min heap 
	int *pos;     /// This is needed for decreaseKey() 
	struct MinHeapNode **array;
};
/// Structure to represent an edge -> distance
struct Edge
{
	Text city1;		/// Name of the first city
	Text city2;		///Name of the second city
	int distance;	/// Distance between cities
	struct Edge *next;
}; 
/// Structure to represent a vertex -> city
struct Vertex
{
	int counter;	/// Position/Index of a node in city list
	Text city;		/// Name of a city
	struct Vertex *next;
};

#endif