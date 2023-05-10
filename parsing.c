#include "monty.h"
/**
 * parse_line - Parse a line of the Monty bytecode file.
 * @line: The line to parse.
 * @line_number: The current line number.
 * @stack: A pointer to the top of the stack.
 *
 * Return: 0 if the line was parsed successfully, otherwise -1.
 */
int parse_line(char *line, unsigned int line_number, stack_t **stack)
{
	char *opcode;
	int n;

	opcode = strtok(line, " \n");

	if (opcode == NULL || *opcode == '#')
		return (0);

	if (strcmp(opcode, "push") == 0)
	{
		n = atoi(strtok(NULL, " \n"));
		push(stack, n);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		return (-1);
	}

	return (0);
}
