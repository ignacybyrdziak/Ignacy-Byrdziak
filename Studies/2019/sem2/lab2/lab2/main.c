#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "functions_and_structures.h"
 
int main()
{
	int i;
	int size;
	struct DaneOsobowe *tab;

	puts("Enter a size of table: ");												//entering size of table
	scanf_s("%d", &size);

	(struct DaneOsobowe*) tab = malloc(size * sizeof(struct DaneOsobowe));			//alocating memory

	while (getchar() != '\n')														//releasing bufor (to prevent missing one name)
		continue;

	for (int i = 0; i < size; ++i)													//scanning the names
	{
		tab[i].id = i + 1;
		int tmp = 0;
		printf("Enter %d name: ", i + 1);
		char tmptab[30];															//helping table
		while ((tmptab[tmp] = getchar()) != '\n')									//giving size to the tmp (to know how long is name)
		{
			++tmp;
		}
		tab[i].name = (char *)malloc(sizeof(char) * (tmp + 1));						//alocating memory for the name
		for (int j = 0; j <= tmp; ++j)
		{
			tab[i].name[j] = tmptab[j];
			if (tmptab[j] == '\n')
			{
				tab[i].name[j] = '\0';
			}
		}
		for (int i = 0; i < 30; ++i)
		{
			tmptab[i] = '\0';
		}
	}

	puts("\n\n");

	qsort(tab, size, sizeof(struct DaneOsobowe), Compare_id);			//sorting by id

	for (int i = 0; i < size; ++i)										//printing table sorted by id
	{
		printf("%d ", i + 1);
		for (int j = 0; tab[i].name[j] != '\0'; ++j)
		{
			printf("%c", tab[i].name[j]);
		}
		puts("\n");
	}

	qsort(tab, size, sizeof(struct DaneOsobowe), Compare_names);		//sorting by name

	for (int i = 0; i < size; ++i)										//printing table sorted by name
	{
		printf("%d ", i + 1);
		for (int j = 0; tab[i].name[j] != '\0'; ++j)					
		{
			printf("%c", tab[i].name[j]);
		}
		puts("\n");
	}

	for (int i = 0; i < size; ++i)										//dealocating memory
	{
		free(tab[i].name);
	}
	free(tab);

	return 0;
}