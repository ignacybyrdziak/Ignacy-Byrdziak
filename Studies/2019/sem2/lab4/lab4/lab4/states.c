#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "functions_and_structures.h"

state_f* tab[numer_of_states] = { settings, small_americano, big_americano, cappuccino, hot_milk, espresso, coffee_power_set, amout_of_water_set, turning_off };

state run_state(state current_state, initial_data *data)
{
	return tab[current_state](data);
}

state small_americano(initial_data *data)
{
	if (data->water > data->amout_of_water)
	{
		if (data->coffee_power < data->coffee)
		{
			data->water -= data->amout_of_water;
			data->coffee -= data->coffee_power;
		}
		else
		{
			if (supplies("coffee", 1, data))
			{
				small_americano(data);
			}
			else
			{
				return;
			}
		}
	}
	else
	{
		if (supplies("water", 2, data))
		{
			small_americano(data);
		}
		else
		{
			return;
		}
	}
	return;
}

state big_americano(initial_data *data)
{
	if (data->water > data->amout_of_water * 2)
	{
		if (data->coffee_power * 2 < data->coffee)
		{
			data->water -= data->amout_of_water * 2;
			data->coffee -= data->coffee_power * 2;
		}
		else
		{
			if (supplies("coffee", 1, data))
			{
				big_americano(data);
			}
			else
			{
				return;
			}
		}
	}
	else
	{
		if (supplies("water", 2, data))
		{
			big_americano(data);
		}
		else
		{
			return;
		}
	}
	return;
}

state cappuccino(initial_data *data)
{
	if (data->water > data->amout_of_water)
	{
		if (data->coffee_power < data->coffee)
		{
			if (data->milk > 0)
			{
				data->coffee -= data->coffee_power;
				data->water -= data->amout_of_water;
				data->milk -= 1;
			}
			else
			{
				if (supplies("milk", 3, data)) {
					cappuccino(data);
				}
				else
				{
					return;
				}
			}
		}
		else
		{
			if (supplies("coffee", 1, data))
			{
				cappuccino(data);
			}
			else
			{
				return;
			}
		}
	}
	else
	{
		if (supplies("water", 2, data))
		{
			cappuccino(data);
		}
		else
		{
			return;
		}
	}
	return;
}

state hot_milk(initial_data *data)
{
	if (data->milk > 0)
	{
		data->milk -= 1;
	}
	else
	{
		if (supplies("milk", 3, data))
		{
			hot_milk(data);
		}
		else
		{
			return;
		}
	}
	return;
}

state espresso(initial_data *data)
{
	if (data->water > data->amout_of_water)
	{
		if (data->coffee_power + 1 < data->coffee)
		{
			data->water -= data->amout_of_water;
			data->coffee -= data->coffee_power + 1;
		}
		else
		{
			if (supplies("coffee", 1, data))
			{
				espresso(data);
			}
			else
			{
				return;
			}
		}
	}
	else
	{
		if (supplies("water", 2, data))
		{
			espresso(data);
		}
		else
		{
			return;
		}
	}
	return;
}

state coffe_power_set(initial_data *data)
{
	int new_power;
	printf("Set new power of coffee from 1-5: ");
	scanf("%d", &new_power);
	if (new_power > 5 || new_power < 1)
	{
		printf("Wrong number", data->amout_of_water);
		return;
	}
	else
	{
		data->coffee_power = new_power;
	}
	system("cls");
	return 0;
}

state settings(initial_data *data)
{
	if (data->coffee > 50 || data->coffee < 0 || data->milk>50 || data->milk < 0 || data->water>50 || data->water < 0) {
		Load(&(data->coffee), &(data->water), &(data->milk), &(data->coffee_power), &(data->amout_of_water));
	}
	printf(MENU);
	int i;
	scanf("%d", &i);
	if (i < 9 && i > 0)
	{
		return i;
	}
	else
	{
		return 10;
	}
	char w;
}

state amout_of_water_set(initial_data *data)
{
	int amout_of_water;
	system("cls");
	printf("Choose amount of water from 1-10: ");
	scanf("%d", &amout_of_water);

	if (amout_of_water > 10 || amout_of_water < 1)
	{
		printf("Wrong number\n");
		system("cls");
		return 0;
	}

	else
	{
		data->amout_of_water = amout_of_water;
	}

	system("cls");
	return 0;
}

state turning_off(initial_data *data)
{
	Save(data);
	return 10;
}