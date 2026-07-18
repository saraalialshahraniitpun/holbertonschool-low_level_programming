#include "main.h"

/**
 * _memcpy - copies memory area.
 * @dest: memory area where bytes are copied to.
 * @src: memory area where bytes are copied from.
 * @n: number of bytes to copy.
 *
 * Return: a pointer to the destination memory area dest.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}

	return (dest);
}
