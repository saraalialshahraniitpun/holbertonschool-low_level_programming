#include "main.h"

/**
 * _atoi - converts a string to an integer.
 * @s: the string to be converted.
 *
 * Return: the integer value of the converted string.
 */
int _atoi(char *s)
{
	int sign = 1;
	int res = 0;
	int started = 0;

	while (*s)
	{
		if (*s == '-')
		{
			sign *= -1;
		}
		else if (*s == '+')
		{
			/* Do nothing for + */
		}
		else if (*s >= '0' && *s <= '9')
		{
			started = 1;
			/* Build number as negative to avoid overflow */
			res = (res * 10) - (*s - '0');
		}
		else if (started)
		{
			/* Stop if non-digit appears after digits */
			break;
		}
		s++;
	}

	/* If final sign is positive, flip the negative result */
	if (sign > 0)
	{
		res = -res;
	}

	return (res);
}
