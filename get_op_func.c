#include "monty.h"

/**
* get_op_func - function to get op functions
* Description:
* @stack: stack
* @line_number: current line numberr
*
* Return: operator or NULL
**/

void get_op_func(stack_t **stack, int line_number)
{
	int i = 0;

	instruction_t ops[] = {
		{"pall", pall}, {"push", push},
		{"pint", pint}, {"pop", pop},
		{"nop", nop}, {"swap", swap},
		{"add", add}, {"sub", sub},
		{"mul", mul}, {"div", divide},
		{"mod", mod}, {"pchar", pchar},
		{"pstr", pstr}, {"rotl", rotl},
		{"rotr", rotr}, {NULL, NULL}
	};

	if (data.opcode[0] == '#')
		return;

	while (ops[i].opcode != NULL)
	{
		if (strcmp(ops[i].opcode, data.opcode) == 0)
		{
			ops[i].f(stack, line_number);
			return;
		}
		i++;
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, data.opcode);
	exit(EXIT_FAILURE);
}
