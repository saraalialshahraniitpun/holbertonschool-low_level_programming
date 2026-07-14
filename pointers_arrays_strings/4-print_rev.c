#include "main.h"

/**
 * print_rev - Prints a string in reverse, followed by a new line
 * @s: The string to print in reverse
 */
void print_rev(char *s)
{
	int len = 0;

	/* Find length of string */
	while (s[len] != '\0')
	{
		len++;
	}

	/* Print in reverse */
	len--;
	while (len >= 0)
	{
		_putchar(s[len]);
		len--;
	}
	_putchar('\n');
}
