#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/* Macros */
#define BUFSIZE 256
#define TOKSIZE 6
#define SUCCESS (1)
#define FAIL (-1)
#define NEUTRAL (0)

/**
* struct stack_s - doubly linked list representation of a stack (or queue)
* @n: integer
* @prev: points to the previous element of the stack (or queue)
* @next: points to the next element of the stack (or queue)
*
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO
*/
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
* struct instruction_s - opcode and its function
* @opcode: the opcode
* @f: function to handle the opcode
*
* Description: opcode and its function
* for stack, queues, LIFO, FIFO
*/
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
* struct line_data_s - data from a line
* @opcode: the opcode
* @num: integer arguement of opcode
* @line: single line of file string
* Description: bytecode instruction and number argument on a line
*/
struct line_data
{
	char *line;
	char opcode[TOKSIZE];
	int num;
	int mode;
} data;

/* utilities */
int _putchar(char c);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_memcpy(char *dest, char *src, unsigned int n);
void *fill_an_array(void *a, int el, unsigned int len);

/* read and parse line */
size_t read_line(ssize_t *fd, stack_t *stack);
void parse_line(void);

/* op functions */
void get_op_func(stack_t **stack, int line_number);
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)));
void push(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void divide(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);

/* Advanced */
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number __attribute__((unused)));
void rotl(stack_t **stack, unsigned int line_number __attribute__((unused)));
void rotr(stack_t **stack, unsigned int line_number __attribute__((unused)));

/* Stack - Queue */
void _stack(stack_t **stack, unsigned int line_number __attribute__((unused)));
void _queue(stack_t **stack, unsigned int line_number __attribute__((unused)));

/* cleanup */
void free_exit(stack_t *stack);

/* Error handlers */
int usage_err(stack_t *stack);
int file_err(stack_t *stack, char *fileName);
int malloc_err(stack_t *stack);
int push_err(stack_t *stack, int line_number);
int pint_err(stack_t *stack, int line_number);

#endif /* MONTY_H */
