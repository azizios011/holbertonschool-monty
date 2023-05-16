#include "monty.h"
/**
 * add - Adds the top two elements of the stack.
 * @stack: A pointer to the head of the stack.
 * @line_number: The current line number.
 *
 * Return: void.
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	int sum = (*stack)->n + (*stack)->next->n;

	pop(stack, line_number);
	(*stack)->n = sum;
}
