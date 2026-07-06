#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints all single digit numbers of base 10 starting from 0,
 * using int instead of char, and putchar only twice.
 * Return: Always 0 (Success)
 */
int main(void)
{
	int num;

	num = 48;
	while (num <= 57)
	{
		putchar(num);
		num++;
	}

	putchar('\n');

	return (0);
}
