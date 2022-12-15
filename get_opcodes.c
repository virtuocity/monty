#include "monty.h"

/**
 * get_opcodes - selects the correct opcode to perform
 * @op: opcode passed
 * Return: pointer to the function that executes the opcode
 */

void (*get_opcodes(char *op))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"add", _add},
		{"swap", _swap},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{NULL, NULL}
	};
	int i;

	for (i = 0; instruct[i].opcode; i++)
	{
		if (_strcmp(instruct[i].opcode, op) == 0)
			break;
	}

	return (instruct[i].f);
}
