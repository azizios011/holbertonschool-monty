#include "monty.h"
/**
 * main - The main function of the program.
 * @argc: The number of command-line arguments passed to the program.
 * @argv: An array of strings containing the command-line
 * arguments passed to the program.
 * Return: 0 on success, non-zero on failure.
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	if (read_file(argv[1], &stack) == -1)
	{
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	free_stack(stack);

	return (0);
}
