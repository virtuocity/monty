#include "monty.h"

/**
 * _mul - multiplies the top element to the second top element of the stack
 * @head: head of the linked list
 * @line_no: line number;
 * Return: no return
 */

void _mul(stack_t **head, unsigned int line_no)
{
	int n = 0;
	stack_t *p = NULL;

	p = *head;
	while (p != NULL)
	{
		p = p->next;
		n++;
	}
	if (n < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", line_no);
		free_globv();
		exit(EXIT_FAILURE);
	}
	p = (*head)->next;
	p->n *= (*head)->n;
	_pop(head, line_no);
}
