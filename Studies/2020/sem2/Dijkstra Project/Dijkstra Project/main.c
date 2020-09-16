#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

//#include "argp.h"
#include "functions.h"

//const char *argp_program_version =
//"argp-ex3 1.0";
//const char *argp_program_bug_address =
//"<bug-gnu-utils@gnu.org>";
//
///* Program documentation. */
//static char doc[] =
//"Argp example #3 -- a program with options and arguments using argp";
//
///* A description of the arguments we accept. */
//static char args_doc[] = "ARG1 ARG2";
//
//static struct argp_option options[] = {
//  {"input",    'i', 0,      0,  "Input data"   },
//  {"print",    'p', 0,          "Print data"   },
//  {"output",   'o', "FILE", 0,
//   "Output to FILE instead of standard output" },
//  { 0 }
//};
//
///* Parse a single option. */
//static error_t parse_opt(int key, char *arg, struct argp_state *state)
//{
//	/* Get the input argument from argp_parse, which we
//	   know is a pointer to our arguments structure. */
//	struct arguments *arguments = state->input;
//
//	switch (key)
//	{
//	case 'p':
//		arguments->printing = 1;
//		break;
//	case 'i':
//		arguments->inputing = 1;
//		break;
//	case 'o':
//		arguments->output_file = arg;
//		break;
//
//	case ARGP_KEY_ARG:
//		if (state->arg_num >= 2)
//			/* Too many arguments. */
//			argp_usage(state);
//
//		arguments->args[state->arg_num] = arg;
//
//		break;
//
//	case ARGP_KEY_END:
//		if (state->arg_num < 2)
//			/* Not enough arguments. */
//			argp_usage(state);
//		break;
//
//	default:
//		return ARGP_ERR_UNKNOWN;
//	}
//	return 0;
//}
//
///* Our argp parser. */
//static struct argp argp = { options, parse_opt, args_doc, doc };
//
///* Used by main to communicate with parse_opt. */
//typedef struct arguments
//{
//	char *args[2];                /* arg1 & arg2 */
//	int printing, inputing;
//	char *output_file;
//};

int main(int argc, char **argv)
{
	//struct arguments arguments;

	///* Default values. */
	//arguments.printing = 0;
	//arguments.inputing = 0;
	//arguments.output_file = "-";

	///* Parse our arguments; every option seen by parse_opt will
	//   be reflected in arguments. */
	//argp_parse(&argp, argc, argv, 0, 0, &arguments);

	int i = 0;
//	FILE *fp;
//	char c;
	int counter = 0, counter2 = 0;
//	char *words = NULL, *word = NULL, c;
	Vertex *list_of_distances=NULL;
	Edge *list_of_cities=NULL;

	char * cities[5] = { "Aaa", "Bielsko-Bia³a", "C", "D", "E" };
	char * cities2[5] = { "Fff", "Ggg", "H", "I", "J" };
	int dist[5] = { 2,4,6,8,10 };
	for (i = 0; i < 5; i++)
	{
		list_of_cities=Add_New_City(cities[i], list_of_cities);
		printf("miasto to %s\n", list_of_cities->city);
		counter++;
	}

	printf("\n");
	for (i = 0; i < 5; i++)
	{
		list_of_distances = Add_New_Distance(cities[i], cities2[i], dist[i], list_of_distances);
		printf("%s %s %d\n", list_of_distances->city1, list_of_distances->city2, list_of_distances->distance);
		counter2++;
	}

	//if (arguments.inputing == 1)
	//{
	//	char str[50];
	//	char* filename = "cities.txt";
	//	fp = fopen(filename, "r");

	//	if (fp == NULL)
	//	{
	//		printf("Could not open file %s", filename);
	//		return 1;
	//	}
	//		//while ((c = fgetc(fp)) != EOF) {
	//		//	if (c == '\n') { c = ' '; }
	//		//	words = (char *)realloc(words, ++i * sizeof(char));
	//		//	words[i - 1] = c;
	//		//}
	//		//word = strtok(words, " ");
	//		//while (word != NULL) {
	//		//	Add_New_City(word, list_of_cities);
	//		//	word = strtok(NULL, " ");
	//		//}
	//		//exit(0);

	//		//if (!Finding_Duplicate_Cities)
	//		//{
	//		//	Add_New_Distance();
	//		//	i++;
	//		//}
	//	fclose(fp);
	//}
	//if (arguments.printing == 1)
	//{

	//	fp = fopen("output_cities", "w");

	//	while(true) //add condition for while
	//	{
	//		printf(fp);
	//	}

	//	fclose(fp);
	//}
	//if (arguments.output_file == 1)
	//{
	//	fp = fopen("output_cities", "w");

	//	while (true) //add condition for while
	//	{
	//		printf(fp);
	//	}

	//	fclose(fp);
	//}

	//exit(0);
}
