#include "monty.h"

/**
* read_line - read a line from the file
* @fd: a pointer to the file descriptore
* @stack: stack
* Return: (Success) a positive number
* ------- (Fail) a negative number
*/
size_t read_line(int *fd, stack_t *stack)
{
	char *csr_ptr, *end_ptr, c, **line = &(data.line);
	size_t size = BUFSIZE, read_st, length, new_size;

	(*line) = malloc(size * sizeof(char));
	if ((*line) == NULL)
		malloc_err(stack);

	for (csr_ptr = *line, end_ptr = (*line) + size;;)
	{
		read_st = read(*fd, &c, 1);
		if (read_st == 0)
			return (0);

		*csr_ptr++ = c;
		if (c == '\n')
		{
			*csr_ptr = '\0';
			return (read_st);
		}
		if (csr_ptr + 2 >= end_ptr)
		{
			new_size = size * 2;
			length = csr_ptr - (*line);
			line = _realloc(line, size * sizeof(char),
			new_size * sizeof(char));
			if (line == NULL)
				malloc_err(stack);
			size = new_size;
			end_ptr = (*line) + size;
			csr_ptr = (*line) + length;
		}
	}
}

/**
* parse_line - a function to parses line to extract opcode
* and line number
* Description:
* Return:
*/

void parse_line(void)
{
	int idx = 0, j, k, l, m, *num;
	char *str = data.line;
	char *opc, numStr[TOKSIZE];

	opc = data.opcode;
	num = &(data.num);
	while (str[idx] == ' ' || str[idx] == '\t')
		idx++;

	for (m = idx, l = 0; str[m] != ' ' && str[m] != '\0'; m++, l++)
		;
	for (j = idx, k = 0; str[j] != '\0' && str[j] != ' ' && str[j] != '\n';
			j++, k++, idx++)
		opc[k] = str[j];
	opc[k] = '\0';
	while ((str[idx] == ' ' || str[idx] == '\t') && str[idx] != '\0')
		idx++;

	for (j = idx, k = 0; str[j] != '\0' && str[j] != ' ' && str[j] != '\n';
		j++, k++, idx++)
		numStr[k] = str[j];
	numStr[k] = '\0';

	for (k = 0; numStr[k]; k++)
	{
		if (k == 0 && numStr[k] == '-')
			continue;
		if (numStr[k] < 48 || numStr[k] > 57)
		{
			data.push = 1;
			return;
		}
	}
	if (numStr[0] == '\0')
		data.push = 1;
	else
		*num = atoi(numStr);
}
