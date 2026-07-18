#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - prints the sum of the two diagonals of a square matrix.
 * @a: pointer to the first element of the matrix (cast to int *).
 * @size: the size of the matrix (width and height).
 *
 * Return: nothing.
 */
void print_diagsums(int *a, int size)
{
	int i = 0;
	int sum1 = 0;
	int sum2 = 0;

	while (i < size)
	{
		/* Elements of the main diagonal: a[0], a[size + 1], a[2*(size + 1)]... */
		sum1 += a[i * (size + 1)];

		/* Elements of the secondary diagonal: a[size - 1], a[2*size - 2]... */
		sum2 += a[(i + 1) * (size - 1)];

		i++;
	}

	printf("%d, %d\n", sum1, sum2);
}
