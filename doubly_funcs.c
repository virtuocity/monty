#include "monty.h"

/**
 *add_dnodeint - add a note at the begining of the doubly link list
 *@head: first position of linked list
 *@n: data to store
 *Return: a doubly linked list
 */

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *tmp;

	if (head == NULL)
		return (NULL);
	tmp = malloc(sizeof(stack_t));
	if (!tmp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_globv();
		exit(EXIT_FAILURE);
	}
	tmp->n = n;
	if (*head == NULL)
	{
		tmp->next = *head;
		tmp->prev = NULL;
		*head = tmp;
		return (*head);
	}
	(*head)->prev = tmp;
	tmp->next = (*head);
	tmp->prev = NULL;
	*head = tmp;
	return (*head);
}

/**
 *add_dnodeint_end - add a note at the end of the doubly link list
 *@head: first position of linked list
 *@n: data to store
 *Return: a doubly linked list
 */

stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *tmp, *op_num;

	if (head == NULL)
		return (NULL);
	tmp = malloc(sizeof(stack_t));
	if (!tmp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_globv();
		exit(EXIT_FAILURE);
	}
	tmp->n = n;
	if (*head == NULL)
	{
		tmp->next = *head;
		tmp->prev = NULL;
		*head = tmp;
		return (*head);
	}
	op_num = *head;
	while (op_num->next)
		op_num = op_num->next;
	tmp->next = op_num->next;
	tmp->prev = op_num;
	op_num->next = tmp;
	return (op_num->next);
}

/**
 * free_dlistint - frees the doubly linked list
 * @head: head of the list
 * Return: no return
 */

void free_dlistint(stack_t *head)
{
	stack_t *p;

	while ((p = head) != NULL)
	{
		head = head->next;
		free(p);
	}
}
