#include "main.h"

/**
 * rev_string - Reverses a string in-place
 * @s: The string to be reversed
 */
void rev_string(char *s)
{
	int len = 0;
	int start = 0;
	int end;
	char temp;

	/* Find length of string */
	while (s[len] != '\0')
	{
		len++;
	}

	end = len - 1;

	/* Swap characters from both ends */
	while (start < end)
	{
		temp = s[start];
		s[start] = s[end];
		s[end] = temp;

		start++;
		end--;
	}
}
