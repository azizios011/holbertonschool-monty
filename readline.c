#include "monty.h"
/**
 * read_file - Read the Monty bytecode file and execute its instructions.
 * @filename: The name of the Monty bytecode file to read.
 * @stack: A pointer to the top of the stack.
 * Return: 0 on success, otherwise -1.
 */
int read_file(char *filename, stack_t **stack)
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	stack_t *new_stack = NULL;
	unsigned int line_number = 0;
	int ret = 0;

	file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		return (-1);
	}

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;

		if (parse_line(line, line_number, &new_stack) == -1)
		{
			ret = -1;
			break;
		}
	}

	free(line);
	fclose(file);
	free_stack(*stack);
	*stack = new_stack;
	return (ret);
}
