#include "monty.h"

/**
 * is_integer - checks if a string is a valid integer
 * @str: the string to check
 *
 * Return: 1 if str is a valid integer, 0 otherwise
 */
int is_integer(char *str)
{
	int i = 0;

	if (str == NULL || *str == '\0')
		return (0);

	if (str[i] == '-')
		i++;

	for (; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}

	return (1);
}
