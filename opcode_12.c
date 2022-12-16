#include "monty.h"

/**
 * _pstr - prints the string of the stack
 * @head: head of the linked list
 * line_no: line number;
 * Return: no return
 */

void _pstr(stack_t **head, unsigned int line_no)
{
	stack_t *p;
	(void)line_no;

	p = *head;
	while (p && p->n > 0 && p->n < 128)
	{
		printf("%c", p->n);
		p = p->next;
	}
	printf("\n");
}
