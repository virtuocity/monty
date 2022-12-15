#include "monty.h"
#include <stdio.h>

global_t globv;

/**
 * init_globv - initializes the global variables
 * @fd: file descriptor
 * Return: no return
 */
void init_globv(FILE *fd)
{
	globv.lifo = 1;
	globv.curr_line = 1;
	globv.arg = NULL;
	globv.head = NULL;
	globv.fd = fd;
	globv.buffer = NULL;
}

/**
 * main - Entry point
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	void (*f)(stack_t **stack, unsigned int line_num);
	FILE *fd;
	size_t size = 256;
	ssize_t no_lines = 0;
	char *lines[2] = {NULL, NULL};

	fd = check_input(argc, argv);
	init_globv(fd);
	no_lines = getline(&globv.buffer, &size, fd);
	while (no_lines != -1)
	{
		lines[0] = _strtok(globv.buffer, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = get_opcodes(lines[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", globv.curr_line);
				dprintf(2, "unknown instruction %s\n", lines[0]);
				free_globv();
				exit(EXIT_FAILURE);
			}
			globv.arg = _strtok(NULL, " \t\n");
			f(&globv.head, globv.curr_line);
		}
		no_lines = getline(&globv.buffer, &size, fd);
		globv.curr_line++;
	}
	free_globv();

	return (0);

}
