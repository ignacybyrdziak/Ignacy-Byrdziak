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

	printf("The program has got default parameters \n-i citiesInput.txt -o citiesOutpit2.txt -p -h \nbut you can change them in Project->Properties->Debugging or \nerase them and input parameters some other way, for exaple through the console\n");

	text input_file, output_file;
	int cities_position = 0, distance_position = 0, mod_counter = 1, character_counter = 0, space_counter;
	struct edge *list_of_distances = NULL;
	struct vertex *list_of_cities = NULL;
	FILE * pFile, *fp;
	char buf[1024], c[20];
	struct edge* tmp = (struct edge *)malloc(sizeof(struct edge));
	tmp->city1 = (char*)malloc(20);
	tmp->city2 = (char*)malloc(20);
	text starting_city[1024];

	for (int n = 0; n < 20; n++)
		c[n] = NULL;

	for (int i = 1; i < argc-1; i++)
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
				while (fgets(buf,1024,pFile) >= 1024)
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
								//	Printing_Distance_On_Called_Position(distance_position, list_of_distances);
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
								//	Printing_City_On_Called_Position(cities_position, list_of_cities);
									cities_position++;
								}
								strcpy_s(tmp->city1, 20, c);
							}
							if (mod_counter % 3 == 2)
							{
								if (Finding_Duplicate_Cities(c, list_of_cities))
								{
									list_of_cities = Add_New_City(c, cities_position, list_of_cities);
								//	Printing_City_On_Called_Position(cities_position, list_of_cities);
									cities_position++;
								}
								strcpy_s(tmp->city2, 20, c);
							}
							mod_counter++;

							for (int n = 0; n < 20; n++)
								c[n] = NULL;
						}
						else
						{
							c[character_counter] = buf[m];
							character_counter++;
						}
					}
				}
			}
			fclose(pFile);
			i++;
			printf("\n");
		}
		else if (strcmp(argv[i], "-o") == 0)
		{
			output_file = argv[i+1];

			struct Graph* graph = createGraph(cities_position);
			struct edge *current_node = list_of_distances;

			while (current_node)
			{
				addEdge(graph, Finding_City_Position_From_A_List(current_node->city1, list_of_cities), Finding_City_Position_From_A_List(current_node->city2, list_of_cities), current_node->distance);
				current_node = current_node->next;
			}
				
			fp = fopen_s(&pFile, output_file, "w");
			printf("Which city from the file, do you want to see distances too?\n");
			scanf_s("%s" ,starting_city, 20);

			dijkstra_output(graph, Finding_City_Position_From_A_List(starting_city, list_of_cities) , pFile);

			fclose(pFile);
			free(pFile);

			Delete_Graph(graph);

			i++;
			printf("\n");
		}
		else if (strcmp(argv[i], "-p") == 0)
		{
			struct Graph* graph = createGraph(cities_position);
			struct edge *current_node = list_of_distances;

			while (current_node)
			{
				addEdge(graph, Finding_City_Position_From_A_List(current_node->city1, list_of_cities), Finding_City_Position_From_A_List(current_node->city2, list_of_cities), current_node->distance);
				current_node = current_node->next;
			}

			printf("Which city from the file, do you want to see distances too?\n");
			scanf_s("%s", starting_city, 20);

			dijkstra(graph, Finding_City_Position_From_A_List(starting_city, list_of_cities));

			Delete_Graph(graph);

			i++;
			printf("\n");
		}
		else if (strcmp(argv[i], "-h") == 0)
		{
			printf("Help Panel:\nPlease use parameters from list below:\n -i if you want to read from choosen file\n -o if you want to save data to choosen file\n -p if you want to print data to console\n\n");
			i++;
			printf("\n");
		}
		else
		{
			printf("Help Panel:\nPlease use parameters from list below:\n -i if you want to read from choosen file\n -o if you want to save data to choosen file\n -p if you want to print data to console\n\n");
			printf("\n");
		}

	}
	printf("\n");

	Delete_City(list_of_cities);
	Delete_Distance(list_of_distances);

	free(tmp->city1);
	free(tmp->city2);
	free(tmp);

	return 0;
}

	