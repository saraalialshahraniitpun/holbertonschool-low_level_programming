#include "main.h"

/**
 * print_chessboard - prints the chessboard.
 * @a: pointer to the 2D array of characters representing the board.
 *
 * Return: nothing.
 */
void print_chessboard(char (*a)[8])
{
	int row = 0;
	int col;

	/* Loop through each row */
	while (row < 8)
	{
		col = 0;
		/* Loop through each column in the current row */
		while (col < 8)
		{
			_putchar(a[row][col]);
			col++;
		}
		_putchar('\n');
		row++;
	}
}
