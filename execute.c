#include "monty.h"

/**
 * execute_file - reads and executes
 * @stack: pointer in top the stack
 */
void execute_file(stack_t **stack)
{
	char *opcode = NULL;
	size_t largeur = 0;
	ssize_t lecture;
	unsigned int line_number = 0;

	while ((lecture = getline(&glob.line, &largeur, glob.file)) != -1)
	{
		line_number++;
		opcode = strtok(glob.line, " \t\r\n\a");
		glob.arg = strtok(NULL, " \n\t");
		if (opcode == NULL || *opcode == '#')
			continue;
		execute_code(opcode, stack, line_number);
	}
}

/**
 * execute_code - executes a
 * @opcode: execute opcode
 * @stack: pointer in top the stack
 * @line_number: line number
 */
void execute_code(char *opcode, stack_t **stack, unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", fnc_push},
		{"pall", fnc_pall},
		{"pint", fnc_pint},
		{"pop", fnc_pop},
		{"swap", fnc_swap},
		{"nop", fnc_nop},
		{"add", fnc_add},
		/*{"sub", fnc_sub},*/
		{"div", fnc_div},
		{"mul", fnc_mul},
		{"mod", fnc_mod},
		{"pchar", fnc_pchar},
		{"pstr", fnc_pstr},

		{NULL, NULL}
	};
	int i;

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	free_stack(*stack);
	fclose(glob.file);
	free(glob.line);
	exit(EXIT_FAILURE);
}
