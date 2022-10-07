#include "monty.h"

/**
* read_line - read a line from the file
* @fd: a pointer to the file descriptor
* @line: string to contain read line
*
* Return: (Success) a positive number
* ------- (Fail) a negative number
*/
size_t read_line(ssize_t *fd, char **line)
{
	char *csr_ptr, *end_ptr, c;
	size_t size = BUFSIZE, read_st, length, new_size;

	(*line) = malloc(size * sizeof(char));
	if ((*line) == NULL)
		return (malloc_err());

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
				return (malloc_err());
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
* @str: string to parse
* @data: global data containing structs
* Return: 0
*/

void parse_line(char *str, line_data *data)
{
	int idx = 0, j, k, l, m, num;
	char *opc, numStr[2] = {' ', '\0'};

	while (str[idx] == ' ' || str[idx] == '\t')
		idx++;

	for (m = idx, l = 0; str[m] != ' ' && str[m] != '\0'; m++, l++)
		;
	opc = malloc(sizeof(char) * (l + 1));
	if (opc == NULL)
		malloc_err();

	for (j = idx, k = 0; str[j] != '\0' && str[j] != ' ' && str[j] != '\n';
			j++, k++, idx++)
		opc[k] = str[j];
	opc[k] = '\0';
	while ((str[idx] == ' ' || str[idx] == '\t') && str[idx] != '\0')
		idx++;

	if (str[idx] < 48 || str[idx] > 57)
		num = -1;
	else
	{
		numStr[0] = str[idx];
		num = atoi(numStr);
	}
	data->opcode = opc;
	data->num = num;
}
