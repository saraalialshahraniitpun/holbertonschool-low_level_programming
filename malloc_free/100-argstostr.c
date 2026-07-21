#include "main.h"
#include <stdlib.h>

/**
 * argstostr - Concatenates all the arguments of the program.
 * @ac: The argument count.
 * @av: The array of argument strings.
 *
 * Return: Pointer to the new string, or NULL if ac == 0, av == NULL,
 *         or memory allocation fails.
 */
char *argstostr(int ac, char **av)
{
	char *str;
	int i, j, k = 0, total_len = 0;

	if (ac == 0 || av == NULL)
		return (NULL);

	/* حساب الطول الكلي المطلوب لكل الحروف + رمز \n لكل وسيط + \0 */
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
			total_len++;
		total_len++; /* لإضافة مكان لـ '\n' */
	}
	total_len++; /* لإضافة مكان لـ '\0' */

	str = malloc(sizeof(char) * total_len);
	if (str == NULL)
		return (NULL);

	/* نسخ الوسائط وإلحاق '\n' بعد كل وسيط */
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
		{
			str[k] = av[i][j];
			k++;
		}
		str[k] = '\n';
		k++;
	}
	str[k] = '\0';

	return (str);
}
