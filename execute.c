#include "monty.h"
/**
 * execute_instruction - executes the given instruction on the stack
 * @opcode: instruction to execute
 * @stack: double pointer to the beginning of the stack_t list
 * @line_number: number of the line being executed
 */
void execute_instruction(stack_t **stack, char *opcode,
unsigned int line_number)
{
	int value;

	if (strcmp(opcode, "push") == 0)
	{
		if (*stack == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		value = (*stack)->n;
		pop(stack, line_number);
		push(stack, value);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		print_stack(*stack);
	}
	else if (strcmp(opcode, "pint") == 0)
	{
		if (*stack == NULL)
		{
			fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
			exit(EXIT_FAILURE);
		}
		printf("%d\n", (*stack)->n);
	}
	else if (strcmp(opcode, "add") == 0)
	{
		if (stack_len(*stack) < 2)
		{
			fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
			exit(EXIT_FAILURE);
		}
		value = (*stack)->n;
		pop(stack, line_number);
		(*stack)->n += value;
	}

}
