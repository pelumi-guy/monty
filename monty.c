#include "monty.h"

/**
 * main - main block
 * Description:
 * @argc: number of command line arguments
 * @argv: array of command line argument strings
 * Return: (0) on success
 * ------ (EXIT_FAILURE) on failure
 */

int main(int argc, char **argv)
{
	size_t r;
	stack_t *stack = NULL;
	/* char *line = data.line; */
	int i;

	if (argc != 2)
		usage_err(stack);

	data.fd = open(argv[1], O_RDONLY);
	if (data.fd == -1)
		file_err(stack, argv[1]);

	data.mode = 0;
	for (i = 1; ; i++)
	{
		r = read_line(&(data.fd), stack);
		if (r == 0)
			break;
		parse_line();
		/* printf("opcode: %s\n", data.opcode); */
		get_op_func(&stack, i);
		free(data.line);
	}
	free_exit(stack);
	return (0);
}
