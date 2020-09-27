#pragma once

#ifndef functions_h
#define functions_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "structures.h"

/**	A utility function to delete an adjacency list node
@param pHead pointer to first list element (head)
*/
void DeleteAdjListNode(struct AdjListNode* pHead);

/**	A utility function to delete an adjacency list
@param pHead pointer to first list element (head)
*/
void DeleteAdjList(struct AdjList* pHead);

/**	A utility function to delete a graph
@param pHead pointer to first list element (head)
*/
void DeleteGraph(struct Graph* pHead);

/** A utility function to delete a list of cities (vertexes in graph)
@param pHead pointer to first list element (head)
*/
void DeleteCity(struct Vertex* phead);

/**	A utility function to delete a list of distances (edges in graph)
@param pHead pointer to first list element (head)
*/
void DeleteDistance(struct Edge* pHead);

/**	A utility function to create a Min Heap 
@param capacity is numer of nodes to MinHeap->array and capacity for MinHeap->capacity
*/
struct MinHeap* createMinHeap(int capacity);

/**	A utility function to create a Min Heap Node
@param v is position of node in array
@param dist is distance in current node
*/
struct MinHeapNode* NewMinHeapNode(int v, int dist);

/** A utility function to create a new adjacency list node
@param dest is the desination vertex in graph (source city)
@param weight is the weight of the edge in the graph (distance)
*/
struct AdjListNode* NewAdjListNode(int dest, int weight);

/** A utility function to create a new edge (distance) in the graph 
@param cityOne is the first city given to new edge (distance)
@param cityTwo is the second city given to new edge (distance)
@param dist is the distance between those two cities
@param head pointer to first list element (head)
*/
struct Edge* AddNewDistance(Text cityOne, Text cityTwo, int dist, struct Edge *head);

/** A utility function to create a new vertex (city) in a graph
@param cityOne is the city given to new vertex
@param counter is position of the city in a list
@param head pointer to first list element (head)
*/
struct Vertex* AddNewCity(Text cityOne, int counter, struct Vertex *head);

/** A utility function that creates a graph of V vertices 
@param V is the number of elements in graph->array and numer of vertexes in graph
*/
struct Graph* CreateGraph(int V);

/** Adds an edge to an undirected graph
@param graph head pointer to first list element (head)
@param src is the source vertex for new edge
@param src is the desination vertex for new edge
@param weight is the weight between two vertexes
*/
void AddEdgeToGraph(struct Graph* graph, int src, int dest, int weight);

/** A utility function to return position of a city with given name of it
@param cityToFind the name of a city to find it's position
@param head is pointer to first list element (head)
*/
int FindingCityPositionFromAList(Text cityToFind, struct Vertex *head);

/** A utility function to return name of a city with position of it
@param position is position of a city to find it's name
@param head is pointer to first list element (head)
*/
Text FindingCityNameFromAList(int position, struct Vertex *head);

/** A utility function to check if there is already distance like this in a list
@param cityOne is giving the first city to compare
@param cityTwo is giving the second city to compare
@param head is pointer to first list element (head)
*/
bool FindingDuplicateDistances(Text cityOne, Text cityTwo, struct Edge *head);

/** /// A utility function to check if there is already city like this in a list
@param cityOne is giving the city to compare
@param head is pointer to first list element (head)
*/
bool FindingDuplicateCities(Text cityOne, struct Vertex *head);

/** A utility function to check if a given vertex 'v' is in min heap or not
@param v is given vertex to check
@param minHeap is pointer to first list element (head)
*/
bool IsInMinHeap(struct MinHeap *minHeap, int v);

/** A utility function to check if the given minHeap is empty or not
@param minHeap is pointer to first list element (head)
*/
int IsEmpty(struct MinHeap* minHeap);

/** A standard function to heapify at given idx. This function also updates position of nodes when they are swapped. Position is needed for decreaseKey()
@param minHeap is pointer to first list element (head)
@param idx gives and index to heapify
*/
void MinHeapify(struct MinHeap* minHeap, int idx);

/** A standard function to extract minimum node from heap 
@param minHeap is pointer to first list element (head)
*/
struct MinHeapNode* ExtractMin(struct MinHeap* minHeap);

/** Function to decrease dist value of a given vertex v. This function uses pos[] of min heap to get the current index of node in min heap 
@param minHeap is pointer to first list element (head)
@param dist is distance to decrease
@param v is vertex to decrese it's dist's value
*/
void DecreaseKey(struct MinHeap* minHeap, int v, int dist);

/** A utility function to swap two nodes of min heap. Needed for min heapify 
@param a is pointer to pointer to first node to swap
@param b is pointer to pointer to second node to swap
*/
void SwapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b);

/** A utility function used to print the solution 
@param dist is an array of distances between given city and other cities
@param n is the number of final distances to print
@param list is pointer to first list element (head), given to write back names of cities, not just thei positions
*/
void PrintArr(int dist[], int n, struct Vertex *list);

/** A utility function used to print the solution into output file
@param dist is an array of distances between given city and other cities
@param n is the number of final distances to print
@param fp is pointer to stream into file, that we are writing solution to
@param list is pointer to first list element (head), given to write back names of cities, not just thei positions
*/
void PrintArrToFile(int dist[], int n, FILE *fp, struct Vertex *list);

/** The main function that calulates distances of shortest paths from src to all vertices. It is a O(ELogV) function.
@param src is the source city in the graph
@param graph is pointer to first list element (head)
@param list is pointer to first list element (head), given to write back names of cities, not just thei positions
*/
void Dijkstra(struct Graph* graph, int src, struct Vertex *list);

/** The main function that calulates distances of shortest paths from src to all vertices. It is a O(ELogV) function. (but it contains printing to output file)
@param src is the source city in the graph
@param graph is pointer to first list element (head)
@param fp is pointer to stream into file, that we are writing solution to
@param list is pointer to first list element (head), given to write back names of cities, not just thei positions
*/
void DijkstraOutput(struct Graph* graph, int src, FILE *fp, struct Vertex *list);

#endif