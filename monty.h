#ifndef _MONTY_H_
#define _MONTY_H_
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * struct global_s - variables -> args, file, line content
 * @arg: value
 * @line: input line content
 * @file: pointer to monty file
 *
 * Description: variables that carries values through the program
 */
typedef struct global_s
{
	char *arg;
	FILE *file;
	char *line;
} glob_t;

extern glob_t glob;

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

/* Function prototypes */
void execute_file(stack_t **stack);
void execute_code(char *opcode, stack_t **stack, unsigned int line_number);

void fnc_push(stack_t **stack, unsigned int line_number);
void fnc_pall(stack_t **stack, unsigned int line_number);
void fnc_pint(stack_t **stack, unsigned int line_number);
void fnc_pop(stack_t **stack, unsigned int line_number);
void fnc_swap(stack_t **stack, unsigned int line_number);
void fnc_add(stack_t **stack, unsigned int line_number);
void fnc_nop(stack_t **stack, unsigned int line_number);
void fnc_sub(stack_t **stack, unsigned int line_number);
void fnc_div(stack_t **stack, unsigned int line_number);
void fnc_mul(stack_t **stack, unsigned int line_number);
void fnc_mod(stack_t **stack, unsigned int line_number);
void fnc_pchar(stack_t **stack, unsigned int line_number);
void fnc_pstr(stack_t **stack, unsigned int line_number);

/* Stack helper functions */
stack_t *node_add(stack_t **stack, const int n);
int fnc_number(char *str);
void free_stack(stack_t *stack);

#endif 
