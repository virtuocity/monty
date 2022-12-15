#include "monty.h"

/**
 * free_globv - frees the global variables
 * Return: no return
 */
void free_globv(void)
{
	free_dlistint(globv.head);
	free(globv.buffer);
	fclose(globv.fd);
}
