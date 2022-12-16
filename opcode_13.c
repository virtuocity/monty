#include "monty.h"

/**
 * _rotl - rotates the first element to the bottom and  the second to the top
 * @head: head of the linked list
 * @line_no: line number;
 * Return: no return
 */

void _rotl(stack_t **head, unsigned int line_no)
{
	stack_t *p = NULL;
	stack_t *q = NULL;
	(void)line_no;

	if (*head == NULL)
		return;

	if ((*head)->next == NULL)
		return;

	p = (*head)->next;
	q = *head;

	while (q->next != NULL)
		q = q->next;

	p->prev = NULL;
	q->next = *head;
	(*head)->next = NULL;
	(*head)->prev = q;
	*head = p;
}
