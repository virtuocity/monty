#include "monty.h"

/**
 * _pop - removes the top element of the stack
 * @doubly: head of the linked list
 * @line_no: line number
 * Return: no return
 */

void _pop(stack_t **doubly, unsigned int line_no)
{
	stack_t *p;

	if (doubly == NULL || *doubly == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", line_no);
		free_globv();
		exit(EXIT_FAILURE);
	}
	p = *doubly;
	*doubly = (*doubly)->next;
	free(p);
}
