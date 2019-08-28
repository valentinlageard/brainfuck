#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "brainfuck.h"

int main(int argc, char **argv)
{
	int memory = 20;
	int verbose = 0;
	int speed = 50;
	int prompt = 0;
	int decimal_print = 0;
	char *instructions = NULL;
	char opt;

	while((opt = getopt(argc, argv, "i:s:m:dvp")) != -1)
	{
		switch(opt)
		{
			case 'i':
				instructions = optarg;
				break;
			case 'v':
				verbose = 1;
				break;
			case 's':
				speed = atoi(optarg);
				break;
			case 'p':
				verbose = 1;
				prompt = 1;
				break;
			case 'm':
				memory = atoi(optarg);
				break;
			case 'd':
				decimal_print = 1;
				break;
			case ':':
				printf("option needs a value\n");
				break;
			case '?':
				printf("unknown option: %c\n", optopt);
				break;
		}
	}
	if (instructions)
		brainfuck(instructions, memory, verbose, speed, prompt, decimal_print);
	else
		print_help();
	return 0;
}
