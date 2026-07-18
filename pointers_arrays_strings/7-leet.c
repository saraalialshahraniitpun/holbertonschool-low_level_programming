#include "main.h"

/**
 * leet - encodes a string into 1337 (leet speak).
 * @s: the string to be encoded.
 *
 * Return: a pointer to the encoded string.
 */
char *leet(char *s)
{
	int i = 0;
	int j;
	char letters[] = "aAeEoOtTlL";
	char numbers[] = "4433007711";

	/* Loop 1: To go through the string */
	while (s[i] != '\0')
	{
		j = 0;
		/* Loop 2: To check against leet characters */
		while (letters[j] != '\0')
		{
			/* The ONLY allowed if statement */
			if (s[i] == letters[j])
			{
				s[i] = numbers[j];
			}
			j++;
		}
		i++;
	}

	return (s);
}
