#include "monty.h"

/**
 * _rotr - reverse the stack
 * @head: head of the linked list
 * @line_no: line number
 * Return: no return
 */

void _rotr(stack_t **head, unsigned int line_no)
{
	stack_t *p = NULL;
	(void)line_no;

	if (*head == NULL)
		return;
	if ((*head)->next == NULL)
		return;
	p = *head;
	while (p->next != NULL)
		p = p->next;
	p->prev->next = NULL;
	p->next = *head;
	p->prev = NULL;
	(*head)->prev = p;
	*head = p;
}
