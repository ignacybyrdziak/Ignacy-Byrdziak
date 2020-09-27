#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "functions.h"

void DeleteAdjListNode(struct AdjListNode* pHead)
{
	struct AdjListNode* tmp = NULL;
	while (pHead)
	{
		tmp = (pHead)->next;
		free(pHead);
		pHead = tmp;
	}
}

void DeleteAdjList(struct AdjList* pHead)
{
	struct AdjList* tmp = NULL;
	while (pHead)
	{
		tmp = (pHead)->head;
		free(pHead);
		pHead = tmp;
	}
}

void DeleteGraph(struct Graph* pHead)
{
	while (pHead)
	{
		struct Graph *tmp = (pHead)->array;
		free(pHead);
		pHead = tmp;
	}
}

void DeleteDistance(struct Edge* pHead)
{
	while (pHead)
	{
		struct Edge *tmp = (pHead)->next;
		free((pHead)->city1);
		free((pHead)->city2);
		free(pHead);
		pHead = tmp;
	}
}

void DeleteCity(struct Vertex* pHead)
{
	struct Vertex* tmp = NULL;

	while (pHead)
	{
		tmp = (pHead)->next;
		free((pHead)->city);
		free(pHead);
		pHead = tmp;
	}
}

struct MinHeap* createMinHeap(int capacity)
{
	struct MinHeap* minHeap = (struct MinHeap*) malloc(sizeof(struct MinHeap));
	minHeap->pos = (int *)malloc(capacity * sizeof(int));
	minHeap->size = 0;
	minHeap->capacity = capacity;
	minHeap->array = (struct MinHeapNode**) malloc(capacity * sizeof(struct MinHeapNode*));
	return minHeap;
}

struct MinHeapNode* NewMinHeapNode(int v, int dist)
{
	struct MinHeapNode* minHeapNode = (struct MinHeapNode*) malloc(sizeof(struct MinHeapNode));
	minHeapNode->v = v;
	minHeapNode->dist = dist;
	return minHeapNode;
}

struct AdjListNode* NewAdjListNode(int dest, int weight)
{
	struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
	newNode->dest = dest;
	newNode->weight = weight;
	newNode->next = NULL;
	return newNode;
}

struct Edge * AddNewDistance(Text city_1, Text city_2, int dist, struct Edge *head)
{
	if (head == NULL)
	{
		head = (struct Edge *)malloc(sizeof(struct Edge));
		head->city1 = (char*)malloc(20);
		head->city2 = (char*)malloc(20);
		strcpy(head->city1, city_1);
		strcpy(head->city2, city_2);
		head->distance = dist;
		head->next = NULL;
		return head;
	}

	struct Edge *current_node = head;

	while (current_node->next != NULL)
		current_node = current_node->next;

	current_node->next = (struct Edge *)malloc(sizeof(struct Edge));
	current_node->next->city1 = (char*)malloc(20);
	current_node->next->city2 = (char*)malloc(20);
	strcpy(current_node->next->city1, city_1);
	strcpy(current_node->next->city2, city_2);
	current_node->next->distance = dist;
	current_node->next->next = NULL;
	return head;
}

struct Vertex* AddNewCity(Text city_1, int c, struct Vertex *head)
{
	if (head == NULL)
	{
		head = (struct Vertex *)malloc(sizeof(struct Vertex));
		head->city = (char*)malloc(20);
		strcpy(head->city, city_1);
		head->counter = c;
		head->next = NULL;
		return head;
	}

	struct Vertex *current_node = head;

	while (current_node->next != NULL)
		current_node = current_node->next;

	current_node->next = (struct Vertex *)malloc(sizeof(struct Vertex));
	current_node->next->city = (char*)malloc(20);
	strcpy(current_node->next->city, city_1);
	current_node->next->counter = c;
	current_node->next->next = NULL;
	return head;
}

struct Graph* CreateGraph(int V)
{
	struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
	graph->V = V;

	/// Create an array of adjacency lists.  Size of array will be V 
	graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));

	/// Initialize each adjacency list as empty by making head as NULL 
	for (int i = 0; i < V; ++i)
		graph->array[i].head = NULL;

	return graph;
}

void AddEdgeToGraph(struct Graph* graph, int src, int dest, int weight)
{
	/// Add an edge from src to dest.  A new node is added to the adjacency 
	/// list of src.  The node is added at the beginning 
	struct AdjListNode* newNode = NewAdjListNode(dest, weight);
	newNode->next = graph->array[src].head;
	graph->array[src].head = newNode;

	/// Since graph is undirected, add an edge from dest to src also 
	newNode = NewAdjListNode(src, weight);
	newNode->next = graph->array[dest].head;
	graph->array[dest].head = newNode;
}

int FindingCityPositionFromAList(Text city_to_find, struct Vertex *head)
{
	struct Vertex *current_node = head;
	while (strcmp(current_node->city, city_to_find) != 0)
		current_node = current_node->next;
	return current_node->counter;
}

Text FindingCityNameFromAList(int position, struct Vertex *head)
{
	struct Vertex *current_node = head;
	while (current_node->counter != position)
		current_node = current_node->next;
	return current_node->city;
}

bool FindingDuplicateDistances(Text city_1, Text city_2, struct Edge *head)
{
	if (head == NULL)
		return true;

	struct Edge * current_node = head;

	while (current_node != NULL)
	{
		if ((strcmp(current_node->city1, city_1) == 0) || (strcmp(current_node->city2, city_2) == 0))
			if ((strcmp(current_node->city1, city_2) == 0) || (strcmp(current_node->city2, city_1) == 0))
				return false;
		current_node = current_node->next;
	}
	return true;
}

bool FindingDuplicateCities(Text city_1, struct Vertex *head)
{
	if (head == NULL)
		return true;

	struct Vertex * current_node = head;

	while (current_node != NULL)
	{
		if ((strcmp(current_node->city, city_1) == 0))
			return false;
		current_node = current_node->next;
	}
	return true;
}

bool IsInMinHeap(struct MinHeap *minHeap, int v)
{
	if (minHeap->pos[v] < minHeap->size)
		return true;
	return false;
}

int IsEmpty(struct MinHeap* minHeap)
{
	return minHeap->size == 0;
}

void MinHeapify(struct MinHeap* minHeap, int idx)
{
	int smallest, left, right;
	smallest = idx;
	left = 2 * idx + 1;
	right = 2 * idx + 2;

	if (left < minHeap->size &&
		minHeap->array[left]->dist < minHeap->array[smallest]->dist)
		smallest = left;

	if (right < minHeap->size &&
		minHeap->array[right]->dist < minHeap->array[smallest]->dist)
		smallest = right;

	if (smallest != idx)
	{
		/// The nodes to be swapped in min heap 
		struct MinHeapNode *smallestNode = minHeap->array[smallest];
		struct MinHeapNode *idxNode = minHeap->array[idx];

		/// Swap positions 
		minHeap->pos[smallestNode->v] = idx;
		minHeap->pos[idxNode->v] = smallest;

		/// Swap nodes 
		SwapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);

		MinHeapify(minHeap, smallest);
	}
}

struct MinHeapNode* ExtractMin(struct MinHeap* minHeap)
{
	if (IsEmpty(minHeap))
		return NULL;

	/// Store the root node 
	struct MinHeapNode* root = minHeap->array[0];

	/// Replace root node with last node 
	struct MinHeapNode* lastNode = minHeap->array[minHeap->size - 1];
	minHeap->array[0] = lastNode;

	/// Update position of last node 
	minHeap->pos[root->v] = minHeap->size - 1;
	minHeap->pos[lastNode->v] = 0;

	/// Reduce heap size and heapify root 
	--minHeap->size;
	MinHeapify(minHeap, 0);

	return root;
}

void DecreaseKey(struct MinHeap* minHeap, int v, int dist)
{
	/// Get the index of v in  heap array 
	int i = minHeap->pos[v];

	/// Get the node and update its dist value 
	minHeap->array[i]->dist = dist;

	/// Travel up while the complete tree is not hepified. 
	/// This is a O(Logn) loop 
	while (i && minHeap->array[i]->dist < minHeap->array[(i - 1) / 2]->dist)
	{
		/// Swap this node with its parent 
		minHeap->pos[minHeap->array[i]->v] = (i - 1) / 2;
		minHeap->pos[minHeap->array[(i - 1) / 2]->v] = i;
		SwapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);

		/// move to parent index 
		i = (i - 1) / 2;
	}
}

void SwapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b)
{
	struct MinHeapNode* t = *a;
	*a = *b;
	*b = t;
}

void PrintArr(int dist[], int n, struct Vertex *list)
{	//napisac funkcje odwrotna, ktora bedzie wpisywala po indeksie nazwe
	printf("\nCity:   Distance from source city:\n");
	for (int i = 0; i < n; ++i)
		printf("%s \t\t %d\n", FindingCityNameFromAList(i, list), dist[i]);
}

void PrintArrToFile(int dist[], int n, FILE *fp, struct Vertex *list)
{
	fprintf(fp, "City:   Distance from source city:\n");
	for (int i = 0; i < n; ++i)
		fprintf(fp,"%s \t\t %d\n", FindingCityNameFromAList(i, list), dist[i]);
}

void Dijkstra(struct Graph* graph, int src, struct Vertex *list)
{
	int V = graph->V;	/// Get the number of vertices in graph 
	int dist[100000];      /// Dist values used to pick minimum weight edge in cut 

	/// minHeap represents set E 
	struct MinHeap* minHeap = createMinHeap(V);

	/// Initialize min heap with all vertices. dist value of all vertices  
	for (int v = 0; v < V; ++v)
	{
		dist[v] = INT_MAX;
		minHeap->array[v] = NewMinHeapNode(v, dist[v]);
		minHeap->pos[v] = v;
	}

	/// Make dist value of src vertex as 0 so that it is extracted first 
	minHeap->array[src] = NewMinHeapNode(src, dist[src]);
	minHeap->pos[src] = src;
	dist[src] = 0;
	DecreaseKey(minHeap, src, dist[src]);

	/// Initially size of min heap is equal to V 
	minHeap->size = V;

	/// In the followin loop, min heap contains all nodes 
	/// whose shortest distance is not yet finalized. 
	while (!IsEmpty(minHeap))
	{
		/// Extract the vertex with minimum distance value 
		struct MinHeapNode* minHeapNode = ExtractMin(minHeap);
		int u = minHeapNode->v; // Store the extracted vertex number 

		/// Traverse through all adjacent vertices of u (the extracted 
		/// vertex) and update their distance values 
		struct AdjListNode* pCrawl = graph->array[u].head;
		while (pCrawl != NULL)
		{
			int v = pCrawl->dest;

			/// If shortest distance to v is not finalized yet, and distance to v 
			/// through u is less than its previously calculated distance 
			if (IsInMinHeap(minHeap, v) && dist[u] != INT_MAX &&
				pCrawl->weight + dist[u] < dist[v])
			{
				dist[v] = dist[u] + pCrawl->weight;

				/// Update distance value in min heap also 
				DecreaseKey(minHeap, v, dist[v]);
			}
			pCrawl = pCrawl->next;
		}
		DeleteAdjListNode(pCrawl);
	}
	/// print the calculated shortest distances 
	PrintArr(dist, V, list);
}

void DijkstraOutput(struct Graph* graph, int src, FILE *fp, struct Vertex *list)
{
	int V = graph->V;	/// Get the number of vertices in graph 
	int dist[100000];      /// Dist values used to pick minimum weight edge in cut 

	/// minHeap represents set E 
	struct MinHeap* minHeap = createMinHeap(V);

	/// Initialize min heap with all vertices. dist value of all vertices  
	for (int v = 0; v < V; ++v)
	{
		dist[v] = INT_MAX;
		minHeap->array[v] = NewMinHeapNode(v, dist[v]);
		minHeap->pos[v] = v;
	}

	/// Make dist value of src vertex as 0 so that it is extracted first 
	minHeap->array[src] = NewMinHeapNode(src, dist[src]);
	minHeap->pos[src] = src;
	dist[src] = 0;
	DecreaseKey(minHeap, src, dist[src]);

	/// Initially size of min heap is equal to V 
	minHeap->size = V;

	/// In the followin loop, min heap contains all nodes 
	/// whose shortest distance is not yet finalized. 
	while (!IsEmpty(minHeap))
	{
		/// Extract the vertex with minimum distance value 
		struct MinHeapNode* minHeapNode = ExtractMin(minHeap);
		int u = minHeapNode->v; /// Store the extracted vertex number 

		/// Traverse through all adjacent vertices of u (the extracted 
		/// vertex) and update their distance values 
		struct AdjListNode* pCrawl = graph->array[u].head;
		while (pCrawl != NULL)
		{
			int v = pCrawl->dest;

			/// If shortest distance to v is not finalized yet, and distance to v 
			/// through u is less than its previously calculated distance 
			if (IsInMinHeap(minHeap, v) && dist[u] != INT_MAX && pCrawl->weight + dist[u] < dist[v])
			{
				dist[v] = dist[u] + pCrawl->weight;

				/// Update distance value in min heap also 
				DecreaseKey(minHeap, v, dist[v]);
			}
			pCrawl = pCrawl->next;
		}
		free(minHeapNode);
	}
	/// print the calculated shortest distances into output file
	PrintArrToFile(dist, V, fp, list);

	free(minHeap->array);
	free(minHeap->pos);
	free(minHeap);
}



