#include "monty.h"

/**
 * _pop - removes the top element of the stack
 * @head: head of the linked list
 * @line_no: line number
 * Return: no return
 */

void _pop(stack_t **head, unsigned int line_no)
{
	stack_t *p;

	if (head == NULL || *head == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", line_no);
		free_globv();
		exit(EXIT_FAILURE);
	}
	p = *head;
	*head = (*head)->next;
	free(p);
}
