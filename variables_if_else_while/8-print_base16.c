#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints all the numbers of base 16 in lowercase,
 * followed by a new line.
 * Return: Always 0 (Success)
 */
int main(void)
{
	char ch;
	ch = '0';
	while (ch <= '9')
	{
		putchar(ch);
		ch++;
	}

	 ch = 'a';
        while (ch <= 'f')
        {
                putchar(ch);
                ch++;
        }

	putchar('\n');

	return(0);
}
