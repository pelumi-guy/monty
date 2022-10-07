#include "monty.h"
/**
* free_exit - a function that frees a stack_t stack.
* Description:
* @stack: pointer to head of stack
* Return:
*/

void free_exit(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}
