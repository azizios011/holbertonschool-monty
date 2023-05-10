#include "monty.h"
/**
 * free_stack - free the stack
 * @stack: pointer to the head of the stack_t list
 * Return: void.
*/
void free_stack(stack_t *stack)
{
	stack_t *tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
