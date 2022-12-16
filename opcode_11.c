#include "monty.h"

/**
 * _pchar - print the char value of the first element
 * @head: head of the linked list
 * @line_no: line number;
 * Return: no return
 */

void _pchar(stack_t **head, unsigned int line_no)
{
	if (head == NULL || *head == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", line_no);
		free_globv();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n < 0 || (*head)->n >= 128)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", line_no);
		free_globv();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
}
