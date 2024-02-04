#include "monty.h"

/**
 * fnc_push - pushes an element
 * @stack: pointer
 * @line_number: current line
 */
void fnc_push(stack_t **stack, unsigned int line_number)
{
	int i;

	if (glob.arg == NULL || !fnc_number(glob.arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(*stack);
		fclose(glob.file);
		free(glob.line);
		exit(EXIT_FAILURE);
	}

	i = atoi(glob.arg);
	if (node_add(stack, i) == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		fclose(glob.file);
		free(glob.line);
		exit(EXIT_FAILURE);
	}
}

/**
 * fnc_number - checks
 * @str: string
 * Return: 1 if string is a number, 0 otherwise
 */
int fnc_number(char *str)
{
	if (str == NULL || *str == '\0')
		return (0);

	if (*str == '-' || *str == '+')
		str++;

	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);

		str++;
	}

	return (1);
}
