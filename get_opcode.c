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
