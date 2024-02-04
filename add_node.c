#include "monty.h"

/**
 * node_add - adds a new node  a stack_t list
 * @stack: pointer
 * @n: value to be added in node
 * Return: pointer to the newly added node
 */
stack_t *node_add(stack_t **stack, const int n)
{
	stack_t *nouveau;

	nouveau = malloc(sizeof(stack_t));
	if (nouveau == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	nouveau->n = n;
	nouveau->prev = NULL;

	if (*stack == NULL)
		nouveau->next = NULL;
	else
	{
		nouveau->next = *stack;
		(*stack)->prev = nouveau;
	}
	*stack = nouveau;

	return (nouveau);
}
