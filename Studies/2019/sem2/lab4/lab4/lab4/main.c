#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "functions_and_structures.h"
 
int main()
{
	initial_data data;
	state current_state = initial_state;

	while (true)
	{
		current_state = run_state(current_state, &data);
		if (current_state<1 || current_state>8) return;
	}
}
