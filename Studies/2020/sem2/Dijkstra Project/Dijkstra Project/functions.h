#pragma once

#ifndef functions_h
#define functions_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "structures.h"

int FindingCityPositionFromAList(Text city_to_find, struct Vertex *head);

Text FindingCityNameFromAList(int position, struct Vertex *head);

struct AdjListNode* NewAdjListNode(int dest, int weight);

struct Graph* CreateGraph(int V);

void AddEdge(struct Graph* graph, int src, int dest, int weight);

void MinHeapify(struct MinHeap* minHeap, int idx);

int IsEmpty(struct MinHeap* minHeap);

struct MinHeapNode* ExtractMin(struct MinHeap* minHeap);

void DecreaseKey(struct MinHeap* minHeap, int v, int dist);

bool IsInMinHeap(struct MinHeap *minHeap, int v);

void PrintArr(int dist[], int n, struct Vertex *list);

void PrintArrToFile(int dist[], int n, FILE *fp, struct Vertex *list);

void Dijkstra(struct Graph* graph, int src, struct Vertex *list);

void DijkstraOutput(struct Graph* graph, int src, FILE *fp, struct Vertex *list);

struct MinHeapNode* NewMinHeapNode(int v, int dist);

void SwapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b);

bool FindingDuplicateDistances(Text city_1, Text city_2, struct Edge *head);

bool FindingDuplicateCities(Text city_1, struct Vertex *head);

struct Edge* AddNewDistance(Text city_1, Text city_2, int dist, struct Edge *head);

struct Vertex* AddNewCity(Text city_1, int counter, struct Vertex *head);

void DeleteAdjListNode(struct AdjListNode* pHead);

void DeleteAdjList(struct AdjList* pHead);

void DeleteGraph(struct Graph* pHead);

void DeleteCity(struct Vertex* phead);

void DeleteDistance(struct Edge* pHead);

#endif