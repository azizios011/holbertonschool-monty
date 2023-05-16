#include "monty.h"

/**
 * parse_input - Parses the input file and executes the opcodes.
 * @fp: A pointer to the input file.
 *
 * Return: void.
 */
void parse_input(FILE *fp)
{
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	while (getline(&line, &len, fp) != -1)
	{
		line_number++;
		char *opcode = get_opcode(line);

		if (!opcode || opcode[0] == '#')
			continue;

		execute_opcode(opcode, &stack, line_number);
	}

	free(line);
	free_stack(stack);
}
