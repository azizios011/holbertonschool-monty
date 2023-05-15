#include "monty.h"
/**
 * print_stack - prints all the elements of a stack
 * @stack: pointer to the top of the stack
 */
void print_stack(stack_t *stack)
{
	stack_t *current = stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
