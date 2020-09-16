#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "functions.h"

bool Finding_Duplicate_Distances(text city_1, text city_2, int dist, Vertex *head)
{
	return 0;
}

bool Finding_Duplicate_Cities(text city_1, Edge *head)
{
	return 0;
}

Vertex * Add_New_Distance(text city_1, text city_2, int dist, Vertex *head)
{
	if (head == NULL)
	{
		head = (Vertex *)malloc(sizeof(Vertex));
		head->city1 = city_1;
		head->city2 = city_2;
		head->distance = dist;
		head->next = NULL;
		return head;
	}

	Vertex *current_node = head;

	while (current_node->next != NULL)
		current_node = current_node->next;

	current_node->next = (Vertex *)malloc(sizeof(Vertex));
	current_node->next->city1 = city_1;
	current_node->next->city2 = city_2;
	current_node->next->distance = dist;
	current_node->next->next = NULL;
	return current_node->next;
}

Edge* Add_New_City(text city_1, Edge *head)
{
	if (head == NULL)
	{
		head = (Edge *)malloc(sizeof(Edge));
		head->city = city_1;
		head->next = NULL;
		return head;
	}

	Edge *current_node = head;
	
	while (current_node->next != NULL)
		current_node = current_node->next;

	current_node->next = (Edge *)malloc(sizeof(Edge));
	current_node->next->city = city_1;
	current_node->next->next = NULL;
	return current_node->next;
}


