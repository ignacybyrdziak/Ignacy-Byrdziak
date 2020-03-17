#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "functions_and_structures.h"

void Save(initial_data *data)
{
	FILE* file;

	if (file = fopen("Previous_state.txt", "w"))
	{
		fprintf(file, "%d\n", data->coffee);
		fprintf(file, "%d\n", data->water);
		fprintf(file, "%d\n", data->milk);
		fprintf(file, "%d\n", data->coffee_power);
		fprintf(file, "%d\n", data->amout_of_water);
		fclose(file);
	}
}

void Load(int *coffee, int* water, int* milk, int* coffee_power, int* amout_of_water)
{
	FILE* file;

	if (file = fopen("Previous_state.txt", "r"))
	{
		fscanf(file, "%d", coffee);
		fscanf(file, "%d", water);
		fscanf(file, "%d", milk);
		fscanf(file, "%d", coffee_power);
		fscanf(file, "%d", amout_of_water);
		fclose(file);
	}
}

bool supplies(int supply, char* current_state, initial_data *data)
{
	char w;
	printf("If there are no more supplies press : 'e'", supply);
	scanf("%c", &w);
	if (w != 'e')
	{
		switch (supply)
		{
		case 1:data->coffee += 50 - data->coffee;
			break;
		case 3:data->milk += 50 - data->milk;
			break;
		case 2: data->water += 50 - data->water;
			break;
		}
		return true;
	}
	return false;
}