#include "monty.h"
/**
 * pint - prints the value at the top of the stack
 * @stack: double pointer to the beginning of the stack_t list
 * @line_number: number of the line being executed
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
