#include "main.h"

/**
 * _memset - fills memory with a constant byte.
 * @s: memory area to be filled.
 * @b: the desired byte to fill the memory with.
 * @n: number of bytes to be filled.
 *
 * Return: a pointer to the memory area s.
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		s[i] = b;
		i++;
	}

	return (s);
}
