#include "monty.h"

/**
 * usage_err - a function that prints handles usage error
 * Description:
 * @stack: stack
 * Return: EXIT_FAILURE
 */

int usage_err(stack_t *stack)
{
	fprintf(stderr, "USAGE: monty file\n");
	free_exit(stack);
	exit(EXIT_FAILURE);
}

/**
 * file_err - a function that handles file opening error
 * Description:
 * @stack: stack
 * @fileName: Name of file passed as argumente
 * Return: EXIT_FAILURE
 */

int file_err(stack_t *stack, char *fileName)
{
	fprintf(stderr, "Error: Can't open file %s\n", fileName);
	free_exit(stack);
	exit(EXIT_FAILURE);
}

/**
 * malloc_err - a function that handles malloc errors
 * Description:
 * @stack: stack
 * Return: EXIT_FAILURE
 */

int malloc_err(stack_t *stack)
{
	fprintf(stderr, "Error: malloc failed\n");
	free_exit(stack);
	exit(EXIT_FAILURE);
}

/**
 * push_err - a function that handles push errors
 * Description:
 * @stack: stack
 * @line_number: index of current line
 * Return: EXIT_FAILURE
 */

int push_err(stack_t *stack, int line_number)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	free_exit(stack);
	exit(EXIT_FAILURE);
}

/**
 * pint_err - a function that handles pint errors
 * Description:
 * @stack: stack
 * @line_number: index of current line
 * Return: EXIT_FAILURE
 */

int pint_err(stack_t *stack, int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	free_exit(stack);
	exit(EXIT_FAILURE);
}
