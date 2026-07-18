#include "main.h"

/**
 * _strncat - concatenates two strings using at most n bytes from src.
 * @dest: the destination string.
 * @src: the source string to be appended.
 * @n: the maximum number of bytes to copy from src.
 *
 * Return: a pointer to the resulting string dest.
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0;
	int j = 0;

	/* Find the end of dest string */
	while (dest[i] != '\0')
	{
		i++;
	}

	/* Copy src to dest until end of src OR n bytes reached */
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	/* Always add the terminating null byte */
	dest[i] = '\0';

	return (dest);
}
