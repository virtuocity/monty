#include "monty.h"

/**
 * _queue - sets the format of the data to a queue (FIFO)
 * @head: head of the linked list
 * @line_no: line number;
 * Return: no return
 */
void _queue(stack_t **head, unsigned int line_no)
{
	(void)head;
	(void)line_no;

	globv.lifo = 0;
}

/**
 * _stack - sets the format fo the data to a stack (LIFO)
 * @head: head of the linked list
 * @line_no: line number;
 * Return: no return
 */
void _stack(stack_t **head, unsigned int line_no)
{
	(void)head;
	(void)line_no;

	globv.lifo = 1;
}
