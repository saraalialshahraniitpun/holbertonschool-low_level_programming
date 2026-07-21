#include "main.h"
#include <stdlib.h>

/**
 * _strdup - Returns a pointer to a newly allocated space in memory,
 *           which contains a copy of the string given as a parameter.
 * @str: The string to duplicate.
 *
 * Return: Pointer to the duplicated string, or NULL if str is NULL
 *         or if insufficient memory was available.
 */
char *_strdup(char *str)
{
	char *dup;
	unsigned int len = 0;
	unsigned int i;

	if (str == NULL)
		return (NULL);

	/* حساب طول السلسلة النصية */
	while (str[len] != '\0')
		len++;

	/* تخصيص ذاكرة تتسع للحروف + حرف نهاية النص '\0' */
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);

	/* نسخ الحروف إلى الذاكرة الجديدة */
	for (i = 0; i <= len; i++)
		dup[i] = str[i];

	return (dup);
}
