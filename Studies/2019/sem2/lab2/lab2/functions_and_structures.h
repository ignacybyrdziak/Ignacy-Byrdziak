#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int Compare_id(struct DaneOsobowe * a, struct DaneOsobowe * b);

int Compare_names(struct DaneOsobowe * a, struct DaneOsobowe * b);

struct DaneOsobowe
{
	int id;
	char* name;
};
