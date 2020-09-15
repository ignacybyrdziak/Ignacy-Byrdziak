#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "argp.h"
#include "functions.h"
#include "structures.h"

const char *argp_program_version =
"argp-ex3 1.0";
const char *argp_program_bug_address =
"<bug-gnu-utils@gnu.org>";

/* Program documentation. */
static char doc[] =
"Argp example #3 -- a program with options and arguments using argp";

/* A description of the arguments we accept. */
static char args_doc[] = "ARG1 ARG2";

static struct argp_option options[] = {
  {"input",    'i', 0,      0,  "Input data"   },
  {"print",    'p', 0,          "Print data"   },
  {"output",   'o', "FILE", 0,
   "Output to FILE instead of standard output" },
  { 0 }
};

/* Parse a single option. */
static error_t parse_opt(int key, char *arg, struct argp_state *state)
{
	/* Get the input argument from argp_parse, which we
	   know is a pointer to our arguments structure. */
	struct arguments *arguments = state->input;

	switch (key)
	{
	case 'p':
		arguments->printing = 1;
		break;
	case 'i':
		arguments->inputing = 1;
		break;
	case 'o':
		arguments->output_file = arg;
		break;

	case ARGP_KEY_ARG:
		if (state->arg_num >= 2)
			/* Too many arguments. */
			argp_usage(state);

		arguments->args[state->arg_num] = arg;

		break;

	case ARGP_KEY_END:
		if (state->arg_num < 2)
			/* Not enough arguments. */
			argp_usage(state);
		break;

	default:
		return ARGP_ERR_UNKNOWN;
	}
	return 0;
}

/* Our argp parser. */
static struct argp argp = { options, parse_opt, args_doc, doc };

/* Used by main to communicate with parse_opt. */
typedef struct arguments
{
	char *args[2];                /* arg1 & arg2 */
	int printing, inputing;
	char *output_file;
};

int main(int argc, char **argv)
{
	struct arguments arguments;

	/* Default values. */
	arguments.printing = 0;
	arguments.inputing = 0;
	arguments.output_file = "-";

	/* Parse our arguments; every option seen by parse_opt will
	   be reflected in arguments. */
	argp_parse(&argp, argc, argv, 0, 0, &arguments);

	if (arguments.inputing == 1)
	{
			FILE *fp;
			char str[50];
			char* filename = "cities.txt";

			fp = fopen(filename, "r");
			if (fp == NULL) {
				printf("Could not open file %s", filename);
				return 1;
			}
			while (fgets(str, 50, fp) != NULL)
				printf("%s", str);
			fclose(fp);
			return 0;
	}
	if (arguments.printing == 1)
	{
		FILE * fp;
		int i;
		fp = fopen("output_cities", "w");

		while(true) //add condition for while
		{
			printf(fp);
		}

		fclose(fp);
		return 0;
	}
	if (arguments.output_file == 1)
	{
		FILE * fp;
		int i;
		fp = fopen("output_cities", "w");

		while (true) //add condition for while
		{
			printf(fp);
		}

		fclose(fp);
		return 0;
	}

	exit(0);
}
