#include "monty.h"
/**
 * pop - removes the top element of the stack
 * @stack: double pointer to the beginning of the stack
 * @line_number: line number of the opcode being executed
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
		free(tmp);
}
