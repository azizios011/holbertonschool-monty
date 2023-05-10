#include "monty.h"
/**
 * push - adds a new node at the beginning of a stack_t list
 * @stack: double pointer to the head of the stack_t list
 * @value: integer to be added to the stack_t list
 *
 * Return: pointer to the newly added node
 */
void push(stack_t **stack, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
		free(new_node);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}
