#include "monty.h"

/**
 * fnc_mul - multiplies the second top
 * @stack: double pointer
 * @line_number: line number
 */
void fnc_mul(stack_t **stack, unsigned int line_number)
{
	int total;
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	total = temp->next->n * temp->n;
	temp->next->n = total;
	*stack = temp->next;
	free(temp);
}
