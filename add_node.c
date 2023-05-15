#include "monty.h"
/**
 * add_node - adds a new node at the beginning of a stack_t list
 * @stack: double pointer to the beginning of the stack_t list
 * @n: integer to be stored in the new node
 *
 * Return: pointer to the new node
 */
stack_t *add_node(stack_t **stack, int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		return (NULL);
	}

		new_node->n = n;
		new_node->prev = NULL;
		new_node->next = *stack;

		if (*stack != NULL)
			(*stack)->prev = new_node;

		*stack = new_node;

		return (new_node);
}
