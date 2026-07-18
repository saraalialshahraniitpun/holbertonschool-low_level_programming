#include "main.h"
#define NULL ((void *)0)

/**
 * _strstr - locates a substring.
 * @haystack: the longer string to search in.
 * @needle: the substring to search for.
 *
 * Return: a pointer to the beginning of the located substring, or NULL.
 */
char *_strstr(char *haystack, char *needle)
{
	int i = 0;
	int j;

	/* If needle is empty, return haystack immediately */
	if (needle[0] == '\0')
	{
		return (haystack);
	}

	while (haystack[i] != '\0')
	{
		j = 0;
		/* Check if substring matches from the current position */
		while (needle[j] != '\0' && haystack[i + j] == needle[j])
		{
			j++;
		}

		/* If we matched the entire needle, return the start point */
		if (needle[j] == '\0')
		{
			return (haystack + i);
		}

		i++;
	}

	return (NULL);
}
