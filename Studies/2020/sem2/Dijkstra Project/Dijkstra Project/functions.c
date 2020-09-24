#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "functions.h"

// A utility function to create a Min Heap 
struct MinHeap* createMinHeap(int capacity)
{
	struct MinHeap* minHeap =
		(struct MinHeap*) malloc(sizeof(struct MinHeap));
	minHeap->pos = (int *)malloc(capacity * sizeof(int));
	minHeap->size = 0;
	minHeap->capacity = capacity;
	minHeap->array =
		(struct MinHeapNode**) malloc(capacity * sizeof(struct MinHeapNode*));
	return minHeap;
}
//
//slistEL * Assinging_Value_To_A_Graf(slistEL *pw, int position, slistEL *head)
//{
//	slistEL *current_node = head;
//	int counter = 0;
//	while (counter != position)
//	{
//		current_node = current_node->next;
//		counter++;
//	}
//	current_node = pw;
//	return head;
//}
//
//Zbiory * Assinging_Value_To_A_Zbior(bool b, int position, Zbiory*head)
//{
//	Zbiory *current_node = head;
//	int counter = 0;
//	while (counter != position)
//	{
//		current_node = current_node->next;
//		counter++;
//	}
//	current_node->p = b;
//	return head;
//}
//
//bool * Is_There_A_Node(int position, slistEL *head)
//{
//	if (head == NULL)
//		return false;
//	slistEL *current_node = head;
//	int counter = 0;
//	while (counter != position)
//	{
//		current_node = current_node->next;
//		if (current_node == NULL)
//			return false;
//		counter++;
//	}
//	return true;
//}
//
int Finding_City_Position_From_A_List(text city_to_find, Vertex *head)
{
	Vertex *current_node = head;
	while (strcmp(current_node->city , city_to_find) != 0)
		current_node = current_node->next;
	return current_node->counter;
}
//
//slistEL *Finding_Value_From_A_Graf(int position, slistEL *head)
//{
//	if (head == false)
//		return NULL;
//	slistEL *current_node = head;
//	int counter = 0;
//	while (counter != position)
//	{
//		current_node = current_node->next;
//		if (current_node == NULL)
//			return NULL;
//		counter++;
//	}
//	return current_node;
//}
//
void Printing_City_On_Called_Position(int position, Vertex *head)
{
	Vertex *current_node = head;
	int counter = 0;
	while (counter != position)
	{
		current_node = current_node->next;
		counter++;
	}
	printf("%d.City: %s\n", position+1, current_node->city);
}

void Printing_Distance_On_Called_Position(int position, Edge *head)
{
	Edge *current_node = head;
	int counter = 0;
	while (counter != position)
	{
		current_node = current_node->next;
		counter++;
	}
	printf("%d.Distance: %s %s %d\n", position+1, current_node->city1, current_node->city2, current_node->distance);
}
//
//slistEL *Add_New_Element_To_Graf(slistEL *head, slistEL *pw)
//{
//	if (head == NULL)
//	{
//		head = (slistEL *)malloc(sizeof(slistEL));
//		head = pw;
//		head->next = NULL;
//		return head;
//	}
//
//	slistEL*current_node = head;
//
//	while (current_node->next != NULL)
//		current_node = current_node->next;
//
//	current_node->next = (slistEL *)malloc(sizeof(slistEL));
//	current_node->next = pw;
//	current_node->next->next = NULL;
//	return head;
//}
//
//Zbiory *Add_New_Element_To_Q(Zbiory *head)
//{
//	if (head == NULL)
//	{
//		head = (Zbiory *)malloc(sizeof(Zbiory));
//		head->p = false;
//		head->next = NULL;
//		return head;
//	}
//
//	Zbiory*current_node = head;
//
//	while (current_node->next != NULL)
//		current_node = current_node->next;
//
//	current_node->next = (Zbiory *)malloc(sizeof(Zbiory));
//	current_node->next->p = false;
//	current_node->next->next = NULL;
//	return head;
//}
//
//Zwykla *Add_New_Element_To_A_List(int val, Zwykla *head)
//{
//	if (head == NULL)
//	{
//		head = (Zwykla *)malloc(sizeof(Zwykla));
//		head->v = val;
//		head->next = NULL;
//		return head;
//	}
//
//	Zwykla*current_node = head;
//
//	while (current_node->next != NULL)
//		current_node = current_node->next;
//
//	current_node->next = (Zwykla *)malloc(sizeof(Zwykla));
//	current_node->next->v = val;
//	current_node->next->next = NULL;
//	return head;
//}
//
//bool Finding_Value_From_Zbior(int position, Zbiory *head)
//{
//	Zbiory *current_node = head;
//	int counter = 0;
//	while (counter != position)
//	{
//		current_node = current_node->next;
//		counter++;
//	}
//	return current_node->p;
//}
//
//Zwykla *Assinging_Value_To_A_List(int val, int position, Zwykla *head)
//{
//	Zwykla *current_node = head;
//	int counter = 0;
//	while (counter != position)
//	{
//		current_node = current_node->next;
//		counter++;
//	}
//	current_node->v = val;
//	return head;
//}



// A utility function to create a new adjacency list node 

void Delete_AdjListNode(struct AdjListNode* pHead)
{
	struct AdjListNode* tmp = NULL;
	while (pHead)
	{
		tmp = (pHead)->next;
		free((pHead)->weight);
		free((pHead)->dest);
		free(pHead);
		pHead = tmp;
	}
}

void Delete_AdjList(struct AdjList* pHead)
{
	struct AdjList* tmp = NULL;
	while (pHead)
	{
		tmp = (pHead)->head;
		free(pHead);
		pHead = tmp;
	}
}

void Delete_Graph(struct Graph* pHead)
{
	while (pHead)
	{
		struct Graph *tmp = (pHead)->array;
		free(pHead);
		pHead = tmp;
	}
}

void Delete_MinHeap(struct MinHeap** pHead)
{
	struct MinHeap* tmp = NULL;
	while (*pHead)
	{
		tmp = (*pHead)->array;
		free((*pHead)->capacity);
		free((*pHead)->pos);
		free((*pHead)->size);
		free(*pHead);
		*pHead = tmp;
	}
}

void Delete_Distance(Edge* pHead)
{
	while (pHead)
	{
		Edge *tmp = (pHead)->next;
		free((pHead)->city1);
		free((pHead)->city2);
		free(pHead);
		pHead = tmp;
	}
}

void Delete_City(Vertex* pHead)
{
	Vertex* tmp = NULL;

	while (pHead)
	{
		tmp = (pHead)->next;
		free((pHead)->city);
		free(pHead);
		pHead = tmp;
	}
}

void Delete_Tmp(Edge* pHead)
{
	while (pHead)
	{
		Edge *tmp = (pHead)->next;
		free(pHead);
		pHead = tmp;
	}
}

struct AdjListNode* newAdjListNode(int dest, int weight)
{
	struct AdjListNode* newNode =
		(struct AdjListNode*) malloc(sizeof(struct AdjListNode));
	newNode->dest = dest;
	newNode->weight = weight;
	newNode->next = NULL;
	return newNode;
}

// A utility function that creates a graph of V vertices 
struct Graph* createGraph(int V)
{
	struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
	graph->V = V;

	// Create an array of adjacency lists.  Size of array will be V 
	graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));

	// Initialize each adjacency list as empty by making head as NULL 
	for (int i = 0; i < V; ++i)
		graph->array[i].head = NULL;

	return graph;
}

// Adds an edge to an undirected graph 
void addEdge(struct Graph* graph, int src, int dest, int weight)
{
	// Add an edge from src to dest.  A new node is added to the adjacency 
	// list of src.  The node is added at the beginning 
	struct AdjListNode* newNode = newAdjListNode(dest, weight);
	newNode->next = graph->array[src].head;
	graph->array[src].head = newNode;

	// Since graph is undirected, add an edge from dest to src also 
	newNode = newAdjListNode(src, weight);
	newNode->next = graph->array[dest].head;
	graph->array[dest].head = newNode;
}

// A standard function to heapify at given idx 
// This function also updates position of nodes when they are swapped. 
// Position is needed for decreaseKey() 
void minHeapify(struct MinHeap* minHeap, int idx)
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
		// The nodes to be swapped in min heap 
		struct MinHeapNode *smallestNode = minHeap->array[smallest];
		struct MinHeapNode *idxNode = minHeap->array[idx];

		// Swap positions 
		minHeap->pos[smallestNode->v] = idx;
		minHeap->pos[idxNode->v] = smallest;

		// Swap nodes 
		swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);

		minHeapify(minHeap, smallest);
	}
}

// A utility function to check if the given minHeap is ampty or not 
int isEmpty(struct MinHeap* minHeap)
{
	return minHeap->size == 0;
}

// Standard function to extract minimum node from heap 
struct MinHeapNode* extractMin(struct MinHeap* minHeap)
{
	if (isEmpty(minHeap))
		return NULL;

	// Store the root node 
	struct MinHeapNode* root = minHeap->array[0];

	// Replace root node with last node 
	struct MinHeapNode* lastNode = minHeap->array[minHeap->size - 1];
	minHeap->array[0] = lastNode;

	// Update position of last node 
	minHeap->pos[root->v] = minHeap->size - 1;
	minHeap->pos[lastNode->v] = 0;

	// Reduce heap size and heapify root 
	--minHeap->size;
	minHeapify(minHeap, 0);

	return root;
}

// Function to decreasy dist value of a given vertex v. This function 
// uses pos[] of min heap to get the current index of node in min heap 
void decreaseKey(struct MinHeap* minHeap, int v, int dist)
{
	// Get the index of v in  heap array 
	int i = minHeap->pos[v];

	// Get the node and update its dist value 
	minHeap->array[i]->dist = dist;

	// Travel up while the complete tree is not hepified. 
	// This is a O(Logn) loop 
	while (i && minHeap->array[i]->dist < minHeap->array[(i - 1) / 2]->dist)
	{
		// Swap this node with its parent 
		minHeap->pos[minHeap->array[i]->v] = (i - 1) / 2;
		minHeap->pos[minHeap->array[(i - 1) / 2]->v] = i;
		swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);

		// move to parent index 
		i = (i - 1) / 2;
	}
}

// A utility function to check if a given vertex 
// 'v' is in min heap or not 
bool isInMinHeap(struct MinHeap *minHeap, int v)
{
	if (minHeap->pos[v] < minHeap->size)
		return true;
	return false;
}

// A utility function used to print the solution 
void printArr(int dist[], int n)
{
	printf("Vertex   Distance from Source\n");
	for (int i = 0; i < n; ++i)
		printf("%d \t\t %d\n", i, dist[i]);
}

// The main function that calulates distances of shortest paths from src to all 
// vertices. It is a O(ELogV) function 
void dijkstra(struct Graph* graph, int src)
{
	int V = graph->V;// Get the number of vertices in graph 
	int dist[100000];      // dist values used to pick minimum weight edge in cut 

	// minHeap represents set E 
	struct MinHeap* minHeap = createMinHeap(V);

	// Initialize min heap with all vertices. dist value of all vertices  
	for (int v = 0; v < V; ++v)
	{
		dist[v] = INT_MAX;
		minHeap->array[v] = newMinHeapNode(v, dist[v]);
		minHeap->pos[v] = v;
	}

	// Make dist value of src vertex as 0 so that it is extracted first 
	minHeap->array[src] = newMinHeapNode(src, dist[src]);
	minHeap->pos[src] = src;
	dist[src] = 0;
	decreaseKey(minHeap, src, dist[src]);

	// Initially size of min heap is equal to V 
	minHeap->size = V;

	// In the followin loop, min heap contains all nodes 
	// whose shortest distance is not yet finalized. 
	while (!isEmpty(minHeap))
	{
		// Extract the vertex with minimum distance value 
		struct MinHeapNode* minHeapNode = extractMin(minHeap);
		int u = minHeapNode->v; // Store the extracted vertex number 

		// Traverse through all adjacent vertices of u (the extracted 
		// vertex) and update their distance values 
		struct AdjListNode* pCrawl = graph->array[u].head;
		while (pCrawl != NULL)
		{
			int v = pCrawl->dest;

			// If shortest distance to v is not finalized yet, and distance to v 
			// through u is less than its previously calculated distance 
			if (isInMinHeap(minHeap, v) && dist[u] != INT_MAX &&
				pCrawl->weight + dist[u] < dist[v])
			{
				dist[v] = dist[u] + pCrawl->weight;

				// update distance value in min heap also 
				decreaseKey(minHeap, v, dist[v]);
			}
			pCrawl = pCrawl->next;
		}
		if (!isEmpty(minHeap))
		{
			Delete_AdjListNode(pCrawl);
		}
	}



	// print the calculated shortest distances 
	printArr(dist, V);
}

void dijkstra_output(struct Graph* graph, int src)
{
	int V = graph->V;// Get the number of vertices in graph 
	int dist[100000];      // dist values used to pick minimum weight edge in cut 

	// minHeap represents set E 
	struct MinHeap* minHeap = createMinHeap(V);

	// Initialize min heap with all vertices. dist value of all vertices  
	for (int v = 0; v < V; ++v)
	{
		dist[v] = INT_MAX;
		minHeap->array[v] = newMinHeapNode(v, dist[v]);
		minHeap->pos[v] = v;
	}

	// Make dist value of src vertex as 0 so that it is extracted first 
	minHeap->array[src] = newMinHeapNode(src, dist[src]);
	minHeap->pos[src] = src;
	dist[src] = 0;
	decreaseKey(minHeap, src, dist[src]);

	// Initially size of min heap is equal to V 
	minHeap->size = V;

	// In the followin loop, min heap contains all nodes 
	// whose shortest distance is not yet finalized. 
	while (!isEmpty(minHeap))
	{
		// Extract the vertex with minimum distance value 
		struct MinHeapNode* minHeapNode = extractMin(minHeap);
		int u = minHeapNode->v; // Store the extracted vertex number 

		// Traverse through all adjacent vertices of u (the extracted 
		// vertex) and update their distance values 
		struct AdjListNode* pCrawl = graph->array[u].head;
		while (pCrawl != NULL)
		{
			int v = pCrawl->dest;

			// If shortest distance to v is not finalized yet, and distance to v 
			// through u is less than its previously calculated distance 
			if (isInMinHeap(minHeap, v) && dist[u] != INT_MAX &&
				pCrawl->weight + dist[u] < dist[v])
			{
				dist[v] = dist[u] + pCrawl->weight;

				// update distance value in min heap also 
				decreaseKey(minHeap, v, dist[v]);
			}
			pCrawl = pCrawl->next;
		}
		if (!isEmpty(minHeap))
		{
			Delete_AdjListNode(pCrawl);
		}
	}



	// print the calculated shortest distances 
	printArr(dist, V);
}

// A utility function to create a new Min Heap Node 
struct MinHeapNode* newMinHeapNode(int v, int dist)
{
	struct MinHeapNode* minHeapNode =
		(struct MinHeapNode*) malloc(sizeof(struct MinHeapNode));
	minHeapNode->v = v;
	minHeapNode->dist = dist;
	return minHeapNode;
}

// A utility function to swap two nodes of min heap. Needed for min heapify 
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b)
{
	struct MinHeapNode* t = *a;
	*a = *b;
	*b = t;
}

bool Finding_Duplicate_Distances(text city_1, text city_2, Edge *head)
{
	if (head == NULL)
		return true;

	Edge * current_node = head;

	while (current_node != NULL)
	{
		if ((strcmp(current_node->city1, city_1) == 0) || (strcmp(current_node->city2, city_2) == 0))
			if ((strcmp(current_node->city1, city_2) == 0) || (strcmp(current_node->city2, city_1) == 0))
				return false;
		current_node = current_node->next;
	}
	return true;
}

bool Finding_Duplicate_Cities(text city_1, Vertex *head)
{
	if (head == NULL)
		return true;

	Vertex * current_node = head;

	while (current_node != NULL)
	{
		if ((strcmp(current_node->city, city_1) == 0))
			return false;
		current_node = current_node->next;
	}
	return true;
}

Edge * Add_New_Distance(text city_1, text city_2, int dist, Edge *head)
{
	if (head == NULL)
	{
		head = (Edge *)malloc(sizeof(Edge));
		head->city1 = (char*)malloc(10);
		head->city2 = (char*)malloc(10);
		strcpy(head->city1, city_1);
		strcpy(head->city2, city_2);
		head->distance = dist;
		head->next = NULL;
		return head;
	}

	Edge *current_node = head;

	while (current_node->next != NULL)
		current_node = current_node->next;

	current_node->next = (Edge *)malloc(sizeof(Edge));
	current_node->next->city1 = (char*)malloc(10);
	current_node->next->city2 = (char*)malloc(10);
	strcpy(current_node->next->city1, city_1);	
	strcpy(current_node->next->city2, city_2);
	current_node->next->distance = dist;
	current_node->next->next = NULL;
	return head;
}

Vertex* Add_New_City(text city_1, int c, Vertex *head)
{
	if (head == NULL)
	{
		head = (Vertex *)malloc(sizeof(Vertex));
		head->city = (char*)malloc(10);
		strcpy(head->city, city_1);
		head->counter = c;
		head->next = NULL;
		return head;
	}

	Vertex *current_node = head;
	
	while (current_node->next != NULL)
		current_node = current_node->next;

	current_node->next = (Vertex *)malloc(sizeof(Vertex));
	current_node->next->city = (char*)malloc(10);
	strcpy(current_node->next->city, city_1);
	current_node->next->counter = c;
	current_node->next->next = NULL;
	return head;
}


