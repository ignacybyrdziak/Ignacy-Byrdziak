#pragma once

#ifndef functions_h
#define functions_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "structures.h"

//Zbiory * Assinging_Value_To_A_Zbior(bool p, int position, Zbiory*head);
//
//slistEL * Assinging_Value_To_A_Graf(slistEL *pw, int position, slistEL *head);
//
//bool * Is_There_A_Node(int position, slistEL *head);
//
int Finding_City_Position_From_A_List(text city_to_find, struct vertex *head);
//
//bool Finding_Value_From_Zbior(int position, Zbiory *head);
//
//slistEL *Finding_Value_From_A_Graf(int position, slistEL *head);
//
//slistEL *Add_New_Element_To_Graf(slistEL *head, slistEL *pw);
//
//Zbiory *Add_New_Element_To_Q(Zbiory *head);
//
//Zwykla *Add_New_Element_To_A_List(int val, Zwykla *head);
//
//Zwykla *Assinging_Value_To_A_List(int val, int position, Zwykla *head);
//
void Printing_City_On_Called_Position(int position, struct vertex *head);

void Printing_Distance_On_Called_Position(int position, struct edge *head);

struct AdjListNode* newAdjListNode(int dest, int weight);

struct Graph* createGraph(int V);

void addEdge(struct Graph* graph, int src, int dest, int weight);

void minHeapify(struct MinHeap* minHeap, int idx);

int isEmpty(struct MinHeap* minHeap);

struct MinHeapNode* extractMin(struct MinHeap* minHeap);

void decreaseKey(struct MinHeap* minHeap, int v, int dist);

bool isInMinHeap(struct MinHeap *minHeap, int v);

void printArr(int dist[], int n);

void printArr_to_File(int dist[], int n, FILE *fp);

void dijkstra(struct Graph* graph, int src);

void dijkstra_output(struct Graph* graph, int src, FILE *fp);

struct MinHeapNode* newMinHeapNode(int v, int dist);

void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b);

bool Finding_Duplicate_Distances(text city_1, text city_2, struct edge *head);

bool Finding_Duplicate_Cities(text city_1, struct vertex *head);

struct edge * Add_New_Distance(text city_1, text city_2, int dist, struct edge *head);

struct vertex* Add_New_City(text city_1, int counter, struct vertex *head);

void Delete_AdjListNode(struct AdjListNode* pHead);

void Delete_Tmp(struct edge** pHead);

void Delete_AdjList(struct AdjList* pHead);

void Delete_Graph(struct Graph* pHead);

void Delete_MinHeap(struct MinHeap** pHead);

void Delete_City(struct vertex* phead);

void Delete_Distance(struct edge* pHead);

#endif