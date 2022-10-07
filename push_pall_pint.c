#include "monty.h"

/**
 * pall - a function that prints all the elements
 * of a stack_t list.
 * Description:
 * @stack: bytecode stack
 * @line_number: argument integer to bytecode instruction
 * Return: Number of nodes.
 */

void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *h = *stack;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
* push - a function that adds a new node at
* the beginning of a stack_t list.
* Description:
* @stack: bytecode stack
* @line_number: argument integer to bytecode instruction
* Return: 0
*/

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *current;

	if (data.num < 0)
		exit(push_err(*stack, line_number));

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		exit(malloc_err(*stack));

	new->n = data.num;
	new->prev = NULL;
	new->next = NULL;
	current = *stack;
	if (*stack == NULL)
		*stack = new;
	else if (data.mode == 0)
	{
		new->next = *stack;
		(*stack)->prev = new;
		*stack = new;
	}
	else if (data.mode == 1)
	{
		while (current->next)
			current = current->next;
		current->next = new;
		new->prev = current;
	}
}

/**
 * pint - a function that prints value at the top of
 * of a stack_t stack.
 * Description:
 * @stack: bytecode stack
 * @line_number: argument integer to bytecode instruction
 * Return: Number of nodes.
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
		pint_err(*stack, line_number);
	else
		printf("%d\n", (*stack)->n);

}
