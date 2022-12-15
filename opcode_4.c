#include "monty.h"

/**
 * _add - adds the top two elements of the stack
 *
 * @head: head of the linked list
 * @line_no: line number;
 * Return: no return
 */

void _add(stack_t **head, unsigned int line_no)
{
	int i = 0;
	stack_t *p = NULL;

	p = *head;

	while (p != NULL)
	{
		p = p->next;
		i++;
	}
	if (i < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", line_no);
		free_globv();
		exit(EXIT_FAILURE);
	}
	p = (*head)->next;
	p->n += (*head)->n;
	_pop(head, line_no);
}
