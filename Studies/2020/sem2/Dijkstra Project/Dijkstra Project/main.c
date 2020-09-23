#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h> 
#include <cstdbool>
#include <string.h>

#include "functions.h"

int main(int argc, char *argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	printf("\n");

	text input_file, output_file;
	int cities_position = 0, distance_position = 0, mod_counter = 1, character_counter = 0, space_counter;
	Edge *list_of_distances = NULL;
	Vertex *list_of_cities = NULL;
	FILE * pFile, *fp;
	char buf[1024], c[10];
	Edge* tmp = (Edge *)malloc(sizeof(Edge));

	for (int n = 0; n < 10; n++)
	{
		c[n] = NULL;
	}

	for (int i = 1; i < argc; i++)
	{
		if (strcmp(argv[i], "-i") == 0)
		{
			input_file = argv[i+1];
			fp = fopen_s(&pFile, input_file, "r");
			if (pFile==NULL)
			{
				fclose(pFile);
				printf("File empty");
			}
			else
			{
				while (fgets(buf,1024,pFile) >= 1024)//nieskoczonosc
				{
					mod_counter = 1;
					space_counter = 0;
					for (int m = 0; m < 1024; m++)
					{
						if (buf[m] == ' ' || buf[m] == '\n' || buf[m] == '\t')
						{
							if (mod_counter % 3 == 0)
							{
								if (Finding_Duplicate_Distances(tmp->city1, tmp->city2, list_of_distances))
								{
									list_of_distances = Add_New_Distance(tmp->city1, tmp->city2, atoi(c), list_of_distances);
									Printing_Distance_On_Called_Position(distance_position, list_of_distances);
									distance_position++;
								}
							}
							character_counter = 0;
							space_counter++;
							if (space_counter == 3)
							{
								break;
							}

							if (mod_counter % 3 == 1)
							{
								if (Finding_Duplicate_Cities(c, list_of_cities))
								{
									list_of_cities = Add_New_City(c, cities_position, list_of_cities);
									Printing_City_On_Called_Position(cities_position, list_of_cities);
									cities_position++;
								}
								tmp->city1 = (text)malloc(sizeof(text));
								strcpy_s(tmp->city1, 10, c);
							}
							if (mod_counter % 3 == 2)
							{
								if (Finding_Duplicate_Cities(c, list_of_cities))
								{
									list_of_cities = Add_New_City(c, cities_position, list_of_cities);
									Printing_City_On_Called_Position(cities_position, list_of_cities);
									cities_position++;
								}
								tmp->city2 = (text)malloc(sizeof(text));
								strcpy_s(tmp->city2, 10, c);
							}
							mod_counter++;

							for (int n = 0; n < 10; n++)
							{
								c[n] = NULL;
							}
						}
						else
						{
							c[character_counter] = buf[m];
							character_counter++;
						}
					}
				}
			}
			i++;
		}
		else if (strcmp(argv[i], "-o") == 0)
		{
			//output_file = argv[i+1];
			//fp = fopen_s(&pFile, input_file, "w");

			struct Graph* graph = createGraph(cities_position);
			while (list_of_distances)
			{
				addEdge(graph, Finding_City_Position_From_A_List(list_of_distances->city1, list_of_cities), Finding_City_Position_From_A_List(list_of_distances->city2, list_of_cities), list_of_distances->distance);
				list_of_distances = list_of_distances->next;
			}
				

			dijkstra(graph, 0);

			//Delete_Vertex(list_of_cities);
			//Delete_Edge(list_of_distances);
			free(graph);

			i++;
		}
		else if (strcmp(argv[i], "-p") == 0)
		{
			struct Graph* graph = createGraph(cities_position);
			while (list_of_distances)
				addEdge(graph, list_of_distances->city1, list_of_distances->city1, list_of_distances->distance);
			
			dijkstra(graph, 0);
			
			//Delete_Vertex(list_of_cities);
			//Delete_Edge(list_of_distances);
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

	