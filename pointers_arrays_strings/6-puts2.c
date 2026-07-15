#include "main.h"

/**
 * puts2 - Prints every other character of a string,
 * starting with the first character, followed by a new line.
 * @str: The input string to process
 */
void puts2(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);

		if (str[i + 1] != '\0')
		{
			i += 2;
		}
		else
		{
			break;
		}
	}
	_putchar('\n');
}
