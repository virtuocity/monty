#include "monty.h"
/**
 * _push - pushes(insert) an element to the stack
 * @doubly: head of the linked list
 * @line_no: line number
 * Return: no return
 */

void _push(stack_t **doubly, unsigned int line_no)
{
	int n, j;

	if (!globv.arg)
	{
		dprintf(2, "L%u: ", line_no);
		dprintf(2, "usage: push integer\n");
		free_globv();
		exit(EXIT_FAILURE);
	}

	for (j = 0; globv.arg[j] != '\0'; j++)
	{
		if (!isdigit(globv.arg[j]) && globv.arg[j] != '-')
		{
			dprintf(2, "L%u: ", line_no);
			dprintf(2, "usage: push integer\n");
			free_globv();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(globv.arg);

	if (globv.lifo == 1)
		add_dnodeint(doubly, n);
	else
		add_dnodeint_end(doubly, n);
}

/**
 * _pall - prints all values on the stack
 * @doubly: head of the linked list
 * @line_no: line numbers
 * Return: no return
 */

void _pall(stack_t **doubly, unsigned int line_no)
{
	stack_t *op_num;
	(void)line_no;

	op_num = *doubly;
	while (op_num)
	{
		printf("%d\n", op_num->n);
		op_num = op_num->next;
	}
}
