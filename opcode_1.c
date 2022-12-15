#include "monty.h"

/**
 * _pint - prints the value at the top of the stack
 * @head: head of the linked list
 * @line_no: line number
 * Return: no return
 */

void _pint(stack_t **head, unsigned int line_no)
{
	(void)line_no;

	if (*head == NULL)
	{
		dprintf(2, "L%u: ", line_no);
		dprintf(2, "can't pint, stack empty\n");
		free_globv();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
