#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "functions.h"
#include "structures.h"


int main(int argc, char *argv[]) {
	char s;
	FILE *plik;
	int i = 1;
	printf("%d\n", argc);
	while (i < argc) {
		if (strcmp(argv[i], "-i") == 0) {
			plik = fopen(argv[i + 1], "r");
			while (fscanf(plik, "%c", &s) != EOF) {
				printf("%c", s);
			}
			fclose(plik);
		}
		if (strcmp(argv[i], "-o") == 0) {
			plik = fopen(argv[i + 1], "w");
			while (s != '\n') {
				scanf("%c", &s);
				fprintf(plik, "%c", s);
			}
			fclose(plik);
		}
		i++;
	}
	if (argc == 1) {
		printf("Wczytaj znaki: ");
		while (1) {
			scanf("%c", &s);
			printf("%c", s);
		}
	}
	return 0;
}
