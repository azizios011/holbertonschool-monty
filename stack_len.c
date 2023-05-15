#include "monty.h"
/**
 * stack_len - Returns the number of elements in a stack
 * @stack: Pointer to the top of the stack
 *
 * Return: Number of elements in the stack
 */
size_t stack_len(const stack_t *stack)
{
	size_t len = 0;

	while (stack != NULL)
	{
		len++;
		stack = stack->next;
	}

	return (len);
}
