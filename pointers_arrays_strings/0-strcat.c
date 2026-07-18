#include "main.h"

/**
 * _strcat - concatenates two strings.
 * @dest: the destination string.
 * @src: the source string to be appended.
 *
 * Return: a pointer to the resulting string dest.
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	/* 1. التحرك حتى الوصول إلى نهاية النص dest */
	while (dest[i] != '\0')
	{
		i++;
	}

	/* 2. نسخ أحرف النص src إلى نهاية dest */
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	/* 3. إضافة الحرف الصِفري لإغلاق النص المدمج */
	dest[i] = '\0';

	return (dest);
}
