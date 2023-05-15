#include "monty.h"
/**
 * free_stack - frees a stack_t list
 * @stack: pointer to the beginning of the stack_t list
 * Return: the pointer.
 */
void free_stack(stack_t *stack)
{
	stack_t *current = stack;

	while (current != NULL)
	{
		current = stack->next;
		free(stack);
		stack = current;
		}
}
