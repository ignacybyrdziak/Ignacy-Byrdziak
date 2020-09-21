#pragma once

#ifndef functions_h
#define functions_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "structures.h"

Zbiory * Assinging_Value_To_A_Zbior(bool p, int position, Zbiory*head);

slistEL * Assinging_Value_To_A_Graf(slistEL *pw, int position, slistEL *head);

bool * Is_There_A_Node(int position, slistEL *head);

int Finding_Value_From_A_List(int position, Zwykla *head);

bool Finding_Value_From_Zbior(int position, Zbiory *head);

slistEL *Finding_Value_From_A_Graf(int position, slistEL *head);

slistEL *Add_New_Element_To_Graf(slistEL *head, slistEL *pw);

Zbiory *Add_New_Element_To_Q(Zbiory *head);

Zwykla *Add_New_Element_To_A_List(int val, Zwykla *head);

Zwykla *Assinging_Value_To_A_List(int val, int position, Zwykla *head);

void Printing_City_On_Called_Position(int position, Edge *head);

void Printing_Distance_On_Called_Position(int position, Vertex *head);

bool Finding_Duplicate_Distances(text city_1, text city_2, Vertex *head);

bool Finding_Duplicate_Cities(text city_1, Edge *head);

Vertex * Add_New_Distance(text city_1, text city_2, int dist, Vertex *head);

Edge * Add_New_City(text city_1, Edge *head);

#endif