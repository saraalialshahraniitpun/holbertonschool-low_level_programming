#include <stdio.h>

/**
 * main - Advanced Simple Calculator with Input Recovery
 *
 * Return: Always 0
 */
int main(void)
{
	int choice = -1;

	do {
		printf("Simple Calculator\n");
		printf("1) Add\n");
		printf("2) Subtract\n");
		printf("3) Multiply\n");
		printf("4) Divide\n");
		printf("0) Quit\n");

		printf("Choice: ");
		if (scanf("%d", &choice) != 1)
		{
			int c;

			printf("Invalid choice\n");
			while ((c = getchar()) != '\n' && c != EOF)
				choice = -1;
				continue;
				}

		if (choice == 0)
		{
			printf("Bye!\n");
		}
		else if (choice >= 1 && choice <= 4)
		{
			int a, b;
			int c;
			while (1)
			{
				printf("A: ");
				if (scanf("%d", &a) == 1)
					break;
				printf("Invalid number\n");
				while ((c = getchar()) != '\n' && c != EOF)
					while (1)
			{
				printf("B: ");
				if (scanf("%d", &b) == 1)
					break;

				printf("Invalid number\n");
				while ((c = getchar()) != '\n' && c != EOF)
					;
			} if (choice == 1)
				printf("Result: %d\n", a + b);
			else if (choice == 2)
				printf("Result: %d\n", a - b);
			else if (choice == 3)
				printf("Result: %d\n", a * b);
			else if (choice == 4)
			{
				if (b == 0)
					printf("Error: division by zero\n");
				else
					printf("Result: %g\n", (double)a / b);
			}
		}
		else if (choice < 0 || choice > 4)
		{
			printf("Invalid choice\n");
		}

	} while (choice != 0);

	return (0);
}
