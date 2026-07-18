#include "main.h"
#define NULL ((void *)0)

/**
 * _strpbrk - searches a string for any of a set of bytes.
 * @s: the string to be scanned.
 * @accept: the string containing the characters to match.
 *
 * Return: a pointer to the matching byte in s, or NULL if not found.
 */
char *_strpbrk(char *s, char *accept)
{
	int i = 0;
	int j;

	while (s[i] != '\0')
	{
		j = 0;
		while (accept[j] != '\0')
		{
			if (s[i] == accept[j])
			{
				return (s + i);
			}
			j++;
		}
		i++;
	}

	return (NULL);
}
