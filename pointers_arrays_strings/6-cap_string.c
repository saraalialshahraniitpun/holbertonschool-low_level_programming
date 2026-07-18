#include "main.h"

/**
 * is_separator - checks if a character is a word separator.
 * @c: the character to check.
 *
 * Return: 1 if it is a separator, 0 otherwise.
 */
int is_separator(char c)
{
	char seps[] = " \t\n,;.!?\"(){}";
	int i = 0;

	while (seps[i] != '\0')
	{
		if (c == seps[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

/**
 * cap_string - capitalizes all words of a string.
 * @s: the string to be modified.
 *
 * Return: a pointer to the modified string.
 */
char *cap_string(char *s)
{
	int i = 0;

	/* Check the very first character of the string */
	if (s[i] >= 'a' && s[i] <= 'z')
	{
		s[i] = s[i] - 32;
	}

	while (s[i] != '\0')
	{
		/* If the current character is a separator */
		if (is_separator(s[i]))
		{
			/* Check if the next character is a lowercase letter */
			if (s[i + 1] >= 'a' && s[i + 1] <= 'z')
			{
				s[i + 1] = s[i + 1] - 32;
			}
		}
		i++;
	}

	return (s);
}
