#include "monty.h"

/**
 * main - main block
 * Description:
 * Return: (0) on success
 * ------ (EXIT_FAILURE) on failure
 */

line_data data;

int main(int argc, char **argv)
{
	ssize_t fd;
	size_t r;
	stack_t *stack = NULL;
	/* char *line = data.line; */
	int i;

	if (argc != 2)
		return (usage_err(stack));

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (file_err(stack, argv[1]));

	for (i = 1; ; i++)
	{
		r = read_line(&fd, &(data.line), stack);
		if (r == 0)
			break;
		parse_line(data.line, &data);
		get_op_func(&stack, i);
		free(data.line);
	}
	free_exit(stack);
	/* free(line); */
	close(fd);
	return (0);
}
