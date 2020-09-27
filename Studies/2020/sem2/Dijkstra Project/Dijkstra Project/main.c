#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 
#include <cstdbool>
#include <string.h>

#include "functions.h"

int main(int argc, char *argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);	//Memory leak searching

	printf("The program has got default parameters \n-i citiesInput.txt -o citiesOutpit2.txt -p -h \nbut you can change them in Project->Properties->Debugging or \nerase them and input parameters some other way, for exaple through the console\n");

	Text inputFile, outputFile;		//Input and output files
	int citiesPostition = 0, distancePosition = 0, columnCounter = 1, characterCounter = 0, whiteMarkCounter;	//Counters to move through input file and count cities and distances
	struct Edge *listOfDistances = NULL;	//Here the list of distances will be storaged
	struct Vertex *listOfCities = NULL;	//Here the list of cities will be storaged
	FILE * pFile, *fp;		//Here we storage our stream
	char buf[1024], character[20];	//Buffer to read from input file and bufer for city names
	struct Edge* tmp = (struct Edge *)malloc(sizeof(struct Edge));	//Temporary node to storage cities to later add them to distance
	tmp->city1 = (char*)malloc(20);
	tmp->city2 = (char*)malloc(20);
	Text startingCity[1024];	//City given by user, wchich we will find shortest ways to

	//Empyting buffer for city name
	for (int n = 0; n < 20; n++)
		character[n] = NULL;

	//Main loop to read parameters given by user
	for (int i = 1; i < argc-1; i++)
	{
		if (strcmp(argv[i], "-i") == 0)	//Argument -i
		{
			inputFile = argv[i+1];
			fp = fopen_s(&pFile, inputFile, "r");	//Opening input file for reading it
			if (pFile==NULL)	//If file is empty, we are closing it
			{
				fclose(pFile);
				printf("File empty");
			}
			else
			{
				while (fgets(buf,1024,pFile) >= 1024)	//Reading from file in a bufer size pieces
				{
					columnCounter = 1;
					whiteMarkCounter = 0;
					for (int m = 0; m < 1024; m++)
					{
						if (buf[m] == ' ' || buf[m] == '\n' || buf[m] == '\t')	//If white mark is found
						{
							if (columnCounter % 3 == 0)
							{
								if (FindingDuplicateDistances(tmp->city1, tmp->city2, listOfDistances))	//Searching if there is already distance like that in a list
								{
									listOfDistances = AddNewDistance(tmp->city1, tmp->city2, atoi(character), listOfDistances); //Adding new distance
									distancePosition++;
								}
							}
							characterCounter = 0;
							whiteMarkCounter++;
							if (whiteMarkCounter == 3)	//End of line in file
							{
								break;
							}

							if (columnCounter % 3 == 1)
							{
								if (FindingDuplicateCities(character, listOfCities)) //Searching if there is already city like that in a list
								{
									listOfCities = AddNewCity(character, citiesPostition, listOfCities); //Adding new city
									citiesPostition++;
								}
								strcpy_s(tmp->city1, 20, character);
							}
							if (columnCounter % 3 == 2)
							{
								if (FindingDuplicateCities(character, listOfCities)) //Searching if there is already city like that in a list
								{
									listOfCities = AddNewCity(character, citiesPostition, listOfCities);	//Adding new city
									citiesPostition++;
								}
								strcpy_s(tmp->city2, 20, character);
							}
							columnCounter++;

							for (int n = 0; n < 20; n++)	//Emptying the character bufer
								character[n] = NULL;
						}
						else
						{
							character[characterCounter] = buf[m];	//Reading from bufer character by character
							characterCounter++;
						}
					}
				}
			}
			fclose(pFile);	//Closing the file
			i++;
			printf("\n");
		}
		else if (strcmp(argv[i], "-o") == 0)	//Argument -o
		{
			outputFile = argv[i+1]; //Reading the output file name

			struct Graph* graph = CreateGraph(citiesPostition);		//Creating the graph with number of nodes equal to citiesPosition counter
			struct Edge *currentNode = listOfDistances;		//Tempporary node to move through list

			while (currentNode)
			{	//Adding the edges to the graph
				AddEdge(graph, FindingCityPositionFromAList(currentNode->city1, listOfCities), FindingCityPositionFromAList(currentNode->city2, listOfCities), currentNode->distance);
				currentNode = currentNode->next;
			}
				
			fp = fopen_s(&pFile, outputFile, "w");	//Opening output file to write in it
			printf("Which city from the file, do you want to see distances too?\n");
			scanf_s("%s" ,startingCity, 20);	//Reading the starting city

			//The Dijkstra shortest path algorithm
			DijkstraOutput(graph, FindingCityPositionFromAList(startingCity, listOfCities) , pFile, listOfCities);

			//Closing and freeing the file
			fclose(pFile);
			free(pFile);

			//Freeing the graph
			DeleteGraph(graph);

			i++;
			printf("\n");
		}
		else if (strcmp(argv[i], "-p") == 0) //Argument -p
		{
		struct Graph* graph = CreateGraph(citiesPostition);		//Creating the graph with number of nodes equal to citiesPosition counter
		struct Edge *currentNode = listOfDistances;		//Tempporary node to move through list

		while (currentNode)
		{	//Adding the edges to the graph
			AddEdge(graph, FindingCityPositionFromAList(currentNode->city1, listOfCities), FindingCityPositionFromAList(currentNode->city2, listOfCities), currentNode->distance);
			currentNode = currentNode->next;
		}

		printf("Which city from the file, do you want to see distances too?\n");
		scanf_s("%s", startingCity, 20);	//Reading the starting city

		//The Dijkstra shortest path algorithm
		Dijkstra(graph, FindingCityPositionFromAList(startingCity, listOfCities), listOfCities);

		//Freeing the graph
		DeleteGraph(graph);

		i++;
		printf("\n");
		}
		else if (strcmp(argv[i], "-h") == 0) //Arumeng -h
		{	//Quick help panel
			printf("Help Panel:\nPlease use parameters from list below:\n -i if you want to read from choosen file\n -o if you want to save data to choosen file\n -p if you want to print data to console\n\n");
			i++;
			printf("\n");
		}
		else	//Default option, if no arugment has been called, or they had beed introduced wrong way
		{	//Quick help panel
			printf("Help Panel:\nPlease use parameters from list below:\n -i if you want to read from choosen file\n -o if you want to save data to choosen file\n -p if you want to print data to console\n\n");
			printf("\n");
		}

	}
	printf("\n");

	//Freeing the lists of cities and distances
	DeleteCity(listOfCities);
	DeleteDistance(listOfDistances);

	//Freeing tempotaty node
	free(tmp->city1);
	free(tmp->city2);
	free(tmp);

	return 0;
}

	