#include "monty.h"

/**
 * get_opcode - Gets the opcode from a line of input.
 * @line: A line of input to extract the opcode from.
 *
 * Return: The opcode as a string.
 */
char *get_opcode(char *line)
{
	char *opcode = strtok(line, " \n\t");

	return (opcode);
}

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

/**
 * main - Entry point to the program
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char **argv)
{
	FILE *fp;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	parse_input(fp);

	fclose(fp);
	exit(EXIT_SUCCESS);
}
