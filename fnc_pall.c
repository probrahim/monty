#include "monty.h"

/**
 * fnc_pall - prints
 * @stack: pointer to the top
 * @line_number: line number
 */
void fnc_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
		(void)line_number;
	}

}
