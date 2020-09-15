#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "functions.h"

Edge * Add_New_Distance(text city_1, text city_2, int dist, Edge *head)
{
	Edge *current_node = head;
	Edge *new_node;
	while (current_node != NULL && current_node->next != NULL) {
		current_node = current_node->next;
	}

	new_node = (Edge *)malloc(sizeof(Edge));
	new_node->city1 = city_1;
	new_node->city2 = city_2;
	new_node->next = NULL;
	if (current_node != NULL)
		current_node->next = new_node;
	else
		head = new_node;
	return head;
}

Vertex * Add_New_City(text city_1, Vertex *head)
{
	Vertex *current_node = head;
	Vertex *new_node;
	while (current_node != NULL && current_node->next != NULL) {
		current_node = current_node->next;
	}

	new_node = (Vertex *)malloc(sizeof(Vertex));
	new_node->city = city_1;
	new_node->next = NULL;
	if (current_node != NULL)
		current_node->next = new_node;
	else
		head = new_node;
	return head;
}


