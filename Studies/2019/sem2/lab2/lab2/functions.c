#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "functions_and_structures.h"

int Compare_id(struct DaneOsobowe * a, struct DaneOsobowe * b)
{
	if (a < b) return -1;
	else if (a == b) return 0;
	else return 1;
}

int Compare_names(struct DaneOsobowe * a, struct DaneOsobowe * b)
{
	//strcmp function returns zero, when a is the same as b,  negative if a < b and positive if a > b

	if (strcmp(a->name, b->name) < 0) return -1;
	else if (strcmp(a->name, b->name) == 0) return 0;
	else return 1;
}