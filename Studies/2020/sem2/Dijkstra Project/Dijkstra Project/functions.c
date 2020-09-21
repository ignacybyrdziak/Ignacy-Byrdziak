#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "functions.h"

slistEL * Assinging_Value_To_A_Graf(slistEL *pw, int position, slistEL *head)
{
	slistEL *current_node = head;
	int counter = 0;
	while (counter != position)
	{
		current_node = current_node->next;
		counter++;
	}
	current_node = pw;
	return head;
}

Zbiory * Assinging_Value_To_A_Zbior(bool b, int position, Zbiory*head)
{
	Zbiory *current_node = head;
	int counter = 0;
	while (counter != position)
	{
		current_node = current_node->next;
		counter++;
	}
	current_node->p = b;
	return head;
}

bool * Is_There_A_Node(int position, slistEL *head)
{
	if (head == NULL)
		return false;
	slistEL *current_node = head;
	int counter = 0;
	while (counter != position)
	{
		current_node = current_node->next;
		if (current_node == NULL)
			return false;
		counter++;
	}
	return true;
}

int Finding_Value_From_A_List(int position, Zwykla *head)
{
	Zwykla *current_node = head;
	int counter = 0;
	while (counter != position)
	{
		current_node = current_node->next;
		counter++;
	}
	return current_node->v;
}

slistEL *Finding_Value_From_A_Graf(int position, slistEL *head)
{
	if (head == false)
		return NULL;
	slistEL *current_node = head;
	int counter = 0;
	while (counter != position)
	{
		current_node = current_node->next;
		if (current_node == NULL)
			return NULL;
		counter++;
	}
	return current_node;
}

void Printing_City_On_Called_Position(int position, Edge *head)
{
	Edge *current_node = head;
	int counter = 0;
	while (counter != position)
	{
		current_node = current_node->next;
		counter++;
	}
	printf("%d. City: %s\n", position+1, current_node->city);
}

void Printing_Distance_On_Called_Position(int position, Vertex *head)
{
	Vertex *current_node = head;
	int counter = 0;
	while (counter != position)
	{
		current_node = current_node->next;
		counter++;
	}
	printf("%d. Distance: %s %s %d\n", position+1, current_node->city1, current_node->city2, current_node->distance);
}

slistEL *Add_New_Element_To_Graf(slistEL *head, slistEL *pw)
{
	if (head == NULL)
	{
		head = (slistEL *)malloc(sizeof(slistEL));
		head = pw;
		head->next = NULL;
		return head;
	}

	slistEL*current_node = head;

	while (current_node->next != NULL)
		current_node = current_node->next;

	current_node->next = (slistEL *)malloc(sizeof(slistEL));
	current_node->next = pw;
	current_node->next->next = NULL;
	return head;
}

Zbiory *Add_New_Element_To_Q(Zbiory *head)
{
	if (head == NULL)
	{
		head = (Zbiory *)malloc(sizeof(Zbiory));
		head->p = false;
		head->next = NULL;
		return head;
	}

	Zbiory*current_node = head;

	while (current_node->next != NULL)
		current_node = current_node->next;

	current_node->next = (Zbiory *)malloc(sizeof(Zbiory));
	current_node->next->p = false;
	current_node->next->next = NULL;
	return head;
}

Zwykla *Add_New_Element_To_A_List(int val, Zwykla *head)
{
	if (head == NULL)
	{
		head = (Zwykla *)malloc(sizeof(Zwykla));
		head->v = val;
		head->next = NULL;
		return head;
	}

	Zwykla*current_node = head;

	while (current_node->next != NULL)
		current_node = current_node->next;

	current_node->next = (Zwykla *)malloc(sizeof(Zwykla));
	current_node->next->v = val;
	current_node->next->next = NULL;
	return head;
}

bool Finding_Value_From_Zbior(int position, Zbiory *head)
{
	Zbiory *current_node = head;
	int counter = 0;
	while (counter != position)
	{
		current_node = current_node->next;
		counter++;
	}
	return current_node->p;
}

Zwykla *Assinging_Value_To_A_List(int val, int position, Zwykla *head)
{
	Zwykla *current_node = head;
	int counter = 0;
	while (counter != position)
	{
		current_node = current_node->next;
		counter++;
	}
	current_node->v = val;
	return head;
}

bool Finding_Duplicate_Distances(text city_1, text city_2, Vertex *head)
{
	if (head == NULL)
		return true;

	Vertex * current_node = head;

	while (current_node != NULL)
	{
		if (current_node->city1 == city_1 || current_node->city2 == city_1)
			if (current_node->city1 == city_2 || current_node->city2 == city_2)
				return false;
		current_node = current_node->next;
	}
	return true;
}

bool Finding_Duplicate_Cities(text city_1, Edge *head)
{
	if (head == NULL)
		return true;

	Edge * current_node = head;

	while (current_node != NULL)
	{
		if (current_node->city == city_1)
			return false;
		current_node = current_node->next;
	}
	return true;
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
	return head;
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
	return head;
}


