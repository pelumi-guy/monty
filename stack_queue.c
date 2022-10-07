#include "monty.h"

/**
* _stack - sets the format of the data to a stack (LIFO).
* This is the default behavior of the program.
* @stack: stack
* @line_number: line number in monty file
* Return: void
*/
void _stack(stack_t **stack __attribute__((unused)),
		unsigned int line_number __attribute__((unused)))
{
	data.mode = 0;
}

/**
* _queue - sets the format of the data to a queue (FIFO).
* @stack: stack
* @line_number: line number in monty file
* Return: void
*/
void _queue(stack_t **stack __attribute__((unused)),
		unsigned int line_number __attribute__((unused)))
{
	data.mode = 1;
}
