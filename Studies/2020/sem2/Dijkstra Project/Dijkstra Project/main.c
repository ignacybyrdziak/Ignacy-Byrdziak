#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h> 
#include <cstdbool>

#include "functions.h"

int main(int argc, char *argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	printf("\n");

	text input_file, output_file;
	int cities_position = 0, distance_position = 0, mod_counter = 1;
	Edge *list_of_distances = NULL;
	Vertex *list_of_cities = NULL;
	FILE * pFile, *fp;
	errno_t err;

	for (int i = 1; i < argc; i++)
	{
		if (strcmp(argv[i], "-i") == 0)
		{
			Edge* tmp = (Edge *)malloc(sizeof(Edge));
			input_file = argv[i+1];
			fp = fopen_s(&pFile, input_file, "r");
			if (fp==NULL)
			{
				fclose(pFile);
				printf("File empty");
			}
			else
			{
				char buf[1023];

				while (fscanf_s(fp, "%s", buf) != EOF)
				{
					if (mod_counter % 3 == 1)
					{
						if (Finding_Duplicate_Cities(buf, list_of_cities))
						{
							list_of_cities = Add_New_City(buf, cities_position, list_of_cities);
							Printing_City_On_Called_Position(cities_position, list_of_cities);
							cities_position++;
						}
						tmp->city1 == buf;
					}
					if (mod_counter % 3 == 2)
					{
						if (Finding_Duplicate_Cities(buf, list_of_cities))
						{
							list_of_cities = Add_New_City(buf, cities_position, list_of_cities);
							Printing_City_On_Called_Position(cities_position, list_of_cities);
							cities_position++;
						}
						tmp->city2 == buf;
					}
					if (mod_counter % 3 == 0)
					{
						if (Finding_Duplicate_Distances(tmp->city1, tmp->city2, list_of_distances))
						{
							list_of_distances = Add_New_Distance(tmp->city1, tmp->city2, buf, list_of_distances);
							Printing_Distance_On_Called_Position(distance_position, list_of_distances);
							distance_position++;
						}
					}
				}
			}
			i++;
		}
		else if (strcmp(argv[i], "-o") == 0)
		{
			output_file = argv[i+1];
			err = fopen_s(&pFile, output_file, "w");

			struct Graph* graph = createGraph(cities_position);
			while (list_of_distances)
				addEdge(graph, list_of_distances->city1, list_of_distances->city1, list_of_distances->distance);

			dijkstra(graph, 0);

			Delete_Vertex(list_of_cities);
			Delete_Edge(list_of_distances);
			free(graph);

			i++;
		}
		else if (strcmp(argv[i], "-p") == 0)
		{
			struct Graph* graph = createGraph(cities_position);
			while (list_of_distances)
				addEdge(graph, list_of_distances->city1, list_of_distances->city1, list_of_distances->distance);
			
			dijkstra(graph, 0);
			
			Delete_Vertex(list_of_cities);
			Delete_Edge(list_of_distances);
			free(graph);

		}
		else if (strcmp(argv[i], "-h") == 0)
		{
			printf("Help Panel:\nPlease use parameters from list below:\n -i if you want to read from choosen file\n -o if you want to save data to choosen file\n -p if you want to print data to console\n\n");
			i++;
		}
		else
		{
			printf("Help Panel:\nPlease use parameters from list below:\n -i if you want to read from choosen file\n -o if you want to save data to choosen file\n -p if you want to print data to console\n\n");
		}
	}

	printf("\n");

	/*Delete_AdjListNode(pHead);

	Delete_AdjList(pHead);

	Delete_Graph(pHead);

	Delete_MinHeap(pHead);

	Delete_Edge(list_of_distances);

	Delete_Vertex(list_of_cities);*/

	//for (int i = 0; i < cities_position; i++)
	//{
		free(list_of_cities);
	//}
		free(list_of_distances);

	return 0;
}

		// Usuwamy tablice dynamiczne

	//	delete[] d;
	//	delete[] p;
	//	delete[] QS;
	//	delete[] S;

	//	for (i = 0; i < CNT; i++)
	//	{
	//		pw = graf[i];
	//		while (pw)
	//		{
	//			rw = pw;
	//			pw = pw->next;
	//			delete rw;
	//		}
	//	}

	//	delete[] graf;

	//	return 0;
	//}

	