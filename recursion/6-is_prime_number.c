#include "main.h"

/**
 * check_prime - recursively checks if n is divisible by i
 * @n: target number
 * @i: current divisor to check
 *
 * Return: 1 if prime, 0 if not
 */
int check_prime(int n, int i)
{
	if (i * i > n)
	{
		return (1);
	}
	if (n % i == 0)
	{
		return (0);
	}
	return (check_prime(n, i + 1));
}

/**
 * is_prime_number - checks if an integer is a prime number
 * @n: target integer
 *
 * Return: 1 if n is prime, 0 otherwise
 */
int is_prime_number(int n)
{
	if (n <= 1)
	{
		return (0);
	}
	return (check_prime(n, 2));
}
