#include "main.h"

/**
 * _strncpy - copies a string up to n bytes.
 * @dest: the destination buffer.
 * @src: the source string to be copied.
 * @n: the maximum number of bytes to be written.
 *
 * Return: a pointer to the destination string dest.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	/* Copy characters from src to dest */
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	/* Pad the remainder with null bytes if n > src length */
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}

	return (dest);
}
