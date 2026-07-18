#include "main.h"

/**
 * _strspn - gets the length of a prefix substring.
 * @s: the initial string to scan.
 * @accept: the string containing the characters to match.
 *
 * Return: the number of bytes in the initial segment of s.
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i = 0;
	unsigned int j;
	unsigned int match;

	while (s[i] != '\0')
	{
		match = 0;
		j = 0;

		while (accept[j] != '\0')
		{
			if (s[i] == accept[j])
			{
				match = 1;
				break;
			}
			j++;
		}

		/* If character is not found in accept, stop counting */
		if (match == 0)
		{
			return (i);
		}
		i++;
	}

	return (i);
}
