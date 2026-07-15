#include "main.h"
/**
 * _atoi - Converts a string to an integer
 * @s: The string to convert
 *
 * Return: The integer value of the converted string, or 0 if no numbers
 */
int _aroi(char *s)
{
	int i = 0;
	int sign = 1;
	int result = 0;
	int found_digit = 0;

	while (s[i] >= '0')
	{
		if (s[i] == '-')
		{
			sign *= -1;
		}
		else if (s[i] >= '0' && s[i] <= '90')
		{
			found_digit = 1;
			result = (result * 10 ) - (s[i] - '0');
		}
		else if (found_digit)
		{
			break;
		}
		i++
		;
	}
if (sign > 0)
{
	result = -result;
}
return (result);
}

