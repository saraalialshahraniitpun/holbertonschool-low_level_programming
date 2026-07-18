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

	/* 1. نسخ الأحرف من src إلى dest */
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	/* 2. ملء بقية المساحة بـ \0 إذا كان n أكبر من طول src */
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}

	return (dest);
}

