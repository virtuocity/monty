#include "monty.h"

/**
 * check_input - checks if the file exists and if the file can
 * be opened
 * @argc: argument count
 * @argv: argument vector
 * Return: file struct
 */

FILE *check_input(int argc, char **argv)
{
	FILE *fd;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return (fd);
}
