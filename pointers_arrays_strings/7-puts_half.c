#include "main.h"

/**
 * puts_half - Prints the second half of a string, followed by a new line
 * @str: The input string to process
 */
void puts_half(char *str)
{
	int len = 0;
	int start;

	/* Calculate length of string */
	while (str[len] != '\0')
	{
		len++;
	}

	/* Determine starting index */
	if (len % 2 == 0)
	{
		start = len / 2;
	}
	else
	{
		start = (len + 1) / 2;
	}

	/* Print characters starting from index 'start' */
	while (str[start] != '\0')
	{
		_putchar(str[start]);
		start++;
	}
	_putchar('\n');
}
