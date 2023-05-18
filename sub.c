#include "monty.h"
/**
 * sub - Subtracts the top element of the stack from the second top element.
 * @stack: A pointer to the head of the stack.
 * @line_number: The current line number.
 *
 * Return: void.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	int num1 = (*stack)->n;
	int num2 = (*stack)->next->n;

	(*stack)->next->n = num2 - num1;

	pop(stack, line_number);
}
