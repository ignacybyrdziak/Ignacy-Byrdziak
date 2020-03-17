#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char MENU[] = "Choose an operation from: \n1.Small americano\t2.Big americano \n3.Cappucino\t4.Hot milk\n5.Espresso\t6.Set coffee power\n7.Set water amount\t8.Turn off the machine\n\n";

typedef enum { initial_state, small_americano, big_americano, cappuccino, hot_milk, espresso, coffee_power_set, amout_of_water_set, turning_off, numer_of_states } state;

typedef state state_f(initial_data *data);

typedef struct initial_data
{
	int coffee;
	int water;
	int milk;
	int coffee_power;
	int amout_of_water;
} initial_data;

void Load(int *coffee, int* water, int* milk, int* coffee_power, int* amout_of_water);

void Save(initial_data *data);

bool supplies(int supply, char* current_state, initial_data *data);

