#include <stdio.h>

/**
 * main - Displays a calculator menu and handles choices
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

		if (scanf("%d", &choice) == 1)
		{
	if (choice == 0)
		{
			printf("Bye!\n");
		}
			
	  else if (choice == 1)
			{
				int a, b;

				printf("A: ");
				scanf("%d", &a);

				printf("B: ");
				scanf("%d", &b);

				printf("Result: %d\n", a + b);
			}
	  else if (choice == 2)
			{
				int a, b;

				printf("A: ");
				scanf("%d", &a);

				printf("B: ");
				scanf("%d", &b);

				printf("Result: %d\n", a - b);
			}
else if (choice == 3)
			{
				int a, b;

				printf("A: ");
				scanf("%d", &a);
				printf("B: ");
				scanf("%d", &b);
				printf("Result: %d\n", a * b);
			}	
      	else if (choice < 0 || choice > 4)
			{
				printf("Invalid choice\n");
			}			}
		}  while (choice != 0);
	return (0);
} 
