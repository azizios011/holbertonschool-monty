#include "monty.h"
/**
 * execute_opcode - Executes the opcode using the appropriate function.
 * @opcode: The opcode as a string.
 * @stack: A pointer to the head of the stack.
 * @line_number: The current line number.
 *
 * Return: void.
 */
void execute_opcode(char *opcode, stack_t **stack, unsigned int line_number)
{
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	int i = 0;

	while (opcodes[i].opcode)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(stack, line_number);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}
