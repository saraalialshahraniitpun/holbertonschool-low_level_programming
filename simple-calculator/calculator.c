#include <stdio.h>

/**
 * main - Displays a calculator menu and handles the quit option
 *
 * Return: Always 0
 */
int main(void)
{
	int choice = -1;

	printf("Simple Calculator\n");
	printf("1) Add\n");
	printf("2) Subtract\n");
	printf("3) Multiply\n");
	printf("4) Divide\n");
	printf("0) Quit\n");

	printf("Choice: ");
	if (scanf("%d", &choice) == 1)
	{
		if (choice == 0)
		{
			printf("Bye!\n");
		}
	}

	return (0);
}
