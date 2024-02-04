#include "monty.h"

/**
 * fnc_div - divides the second top element
 * @stack: double pointer
 * @line_number: current line
 */
void fnc_div(stack_t **stack, unsigned int line_number)
{
	int total;
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	total = temp->next->n / temp->n;
	temp->next->n = total;
	*stack = temp->next;
	free(temp);
}
