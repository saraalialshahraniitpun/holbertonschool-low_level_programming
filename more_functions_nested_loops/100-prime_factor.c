#include <stdio.h>

/**
 * main - Finds and prints the largest prime factor of the number 612852475143,
 * followed by a new line.
 *
 * Return: Always 0
 */
int main(void)
{
	long int n = 612852475143;
	long int divisor = 2;

	while (n % divisor == 0)
	{
		n /= divisor;
	}

	divisor = 3;
	while (divisor * divisor <= n)
	{
		if (n % divisor == 0)
		{
			n /= divisor;
		}
		else
		{
			divisor += 2;
		}
	}

	if (n > 1)
	{
		printf("%ld\n", n);
	}
	else
	{
		printf("%ld\n", divisor);
	}

	return (0);
}
