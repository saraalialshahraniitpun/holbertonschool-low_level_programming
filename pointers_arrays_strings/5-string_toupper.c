#include "main.h"

/**
 * reverse_array - reverses the content of an array of integers.
 * @a: the array of integers to be reversed.
 * @n: the number of elements in the array.
 *
 * Return: nothing.
 */
void reverse_array(int *a, int n)
{
	int i = 0;
	int temp;

	/* Loop until the counter reaches the middle of the array */
	while (i < n / 2)
	{
		temp = a[i];
		a[i] = a[n - 1 - i];
		a[n - 1 - i] = temp;
		i++;
	}
}
