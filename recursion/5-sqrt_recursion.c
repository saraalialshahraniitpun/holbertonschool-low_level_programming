#include "main.h"

/**
 * _sqrt_helper - checks for the natural square root of a number
 * @n: target number
 * @i: current test root
 *
 * Return: natural square root, or -1 if not found
 */
int _sqrt_helper(int n, int i)
{
	if (i * i == n)
	{
		return (i);
	}
	if (i * i > n)
	{
		return (-1);
	}
	return (_sqrt_helper(n, i + 1));
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: number to find square root for
 *
 * Return: natural square root of n, or -1 if n does not have one
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	return (_sqrt_helper(n, 0));
}
