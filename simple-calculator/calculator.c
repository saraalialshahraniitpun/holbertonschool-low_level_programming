#include <stdio.h>

/**
 * main - Displays a calculator menu and handles choices
 *
 * Return: Always 0
 */
int main(void)
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
	  else if (choice < 0 || choice > 4)
			{
				printf("Invalid choice\n");
			}
	return (0);
} 
