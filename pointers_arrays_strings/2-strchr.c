#include "main.h"
#define NULL ((void *)0)

/**
 * _strchr - locates a character in a string.
 * @s: the string to search in.
 * @c: the character to find.
 *
 * Return: a pointer to the first occurrence, or NULL if not found.
 */
char *_strchr(char *s, char c)
{
	int i = 0;

	/* Loop through the string including the null terminator */
	while (s[i] >= '\0')
	{
		if (s[i] == c)
		{
			return (s + i);
		}
		if (s[i] == '\0')
		{
			break;
		}
		i++;
	}

	return (NULL);
}
