#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "functions.h"

int main() {
	char PESEL[12];
	bool End = false;
	while (!End) {
		for (int i = 0; i < 12; i++) {
			scanf_s("%c", &PESEL[i]);
			if (57 < PESEL[i] || 48 > PESEL[i]) break;
		}
		if (Check_PESEL(PESEL)) {									//if PESEL is valid
			printf("PESEL: Valid\n");
			Check_Sex(PESEL);
			Check_Date(PESEL);
		}
		else {
			printf("PESEL: Invalid, press Enter to continue\n");
			char g;
			while ((g = getchar()) != '\n' && g != EOF)				//if too many numbers
				/* discard */;
		}

		printf("Continue with program? If so, type 'Y', otherwise, press anyting else\n");
		char The_end;
		scanf_s("%c", &The_end);
		char g;
		if (The_end == 89)											//clean
			while ((g = getchar()) != '\n' && g != EOF)
				/* discard */;
		else End = true;											//end
	}
}
