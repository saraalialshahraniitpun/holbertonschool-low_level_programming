#include "main.h"

/**
 * more_numbers - Prints 10 times the numbers, from 0 to 14,
 * followed by a new line.
 *
 * Return: void
 */
void more_numbers(void)
{
	int row, i;

	for (row = 0; row < 10; row++)
	{
		for (i = 0; i <= 14; i++)
		{
			if (i > 9)
			{
				_putchar((i / 10) + '0'); /* المرة الأولى */
			}
			_putchar((i % 10) + '0'); /* المرة الثانية */
		}
		_putchar('\n'); /* المرة الثالثة */
	}
}
