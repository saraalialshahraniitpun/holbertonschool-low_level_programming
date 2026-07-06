#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints the alphabet in lowercase, and then in uppercase,
 * followed by a new line, using putchar only thrice.
 * Return: Always 0 (Success)
 */
int main(void)
{
	char ch;
	ch ='a';
	while (ch <= 'z')
	{
		putchar(ch);
		ch++;
	}
	 ch ='A';
        while (ch <= 'Z')
        {
                putchar(ch);
                ch++;
        }
	putchar('\n');

	return(0);
}

