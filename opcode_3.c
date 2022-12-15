#include "monty.h"

/**
 * _swap - swaps the top two elements of the stack
 *
 * @doubly: head of the linked list
 * @line_no: line number
 * Return: no return
 */

void _swap(stack_t **head, unsigned int line_no)
{
	int m = 0;
	stack_t *p = NULL;

	p = *head;
	while (p)
	{
		p = p->next;
		m++;
	}
	if (m < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", line_no);
		free_globv();
		exit(EXIT_FAILURE);
	}
	p = *head;
	*head = (*head)->next;
	p->next = (*head)->next;
	p->prev = *head;
	(*head)->next = p;
	(*head)->prev = NULL;
}
