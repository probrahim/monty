#include "monty.h"

/**
 * fnc_pchar - prints the character
 * @stack: pointer
 * @line_number: current line number
 */
void fnc_pchar(stack_t **stack, unsigned int line_number)
{
	int inside;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	inside = (*stack)->n;
	if (inside < 0 || inside > 127)
	{
		fprintf(stderr, "L%d: can't pchar, inside out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", inside);
}
