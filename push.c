#include "monty.h"

/**
 * push - Pushes an element to the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number being executed from script file
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *n = strtok(NULL, " \n\t");
	int num;

	if (!n || !is_integer(n))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	num = atoi(n);
	if (add_node(stack, num) == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}
