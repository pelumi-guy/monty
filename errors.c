#include "monty.h"

/**
 * usage_err - a function that prints handles usage error
 * Description:
 * Return: EXIT_FAILURE
 */

int usage_err(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * file_err - a function that handles file opening error
 * Description:
 * @fileName: Name of file passed as argumente
 * Return: EXIT_FAILURE
 */

int file_err(char *fileName)
{
	fprintf(stderr, "Error: Can't open file %s\n", fileName);
	return (EXIT_FAILURE);
}

/**
 * malloc_err - a function that handles malloc errors
 * Description:
 * Return: EXIT_FAILURE
 */

int malloc_err(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * push_err - a function that handles push errors
 * Description:
 * @line_number: index of current line
 * Return: EXIT_FAILURE
 */

int push_err(int line_number)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pint_err - a function that handles pint errors
 * Description:
 * @line_number: index of current line
 * Return: EXIT_FAILURE
 */

int pint_err(int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}
