#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "functions.h"

int main() {
	char PESEL[12];
	bool End = false;
	while (!End) {
		for (int i = 0; i < 12; i++) {
			scanf_s("%c", &PESEL[i], 1);
			if (57 < PESEL[i] || 48 > PESEL[i]) break;
		}
		if (Check_PESEL(PESEL)) {							//if PESEL is valid
			printf("Valid PESEL\n");
			Check_Sex(PESEL);
			Check_Date(PESEL);
		}

	}
}