#include <stdio.h>

/**
 * main - Displays a calculator menu and handles choices
 *
 * Return: Always 0
 */
int main(void)
{
	int choice = -1;

	do { /* 1. بداية اللوب */
		printf("Simple Calculator\n");
		printf("1) Add\n");
		printf("2) Subtract\n");
		printf("3) Multiply\n");
		printf("4) Divide\n");
		printf("0) Quit\n");

		printf("Choice: ");

		if (scanf("%d", &choice) == 1)
		{ /* 2. بداية قوس الـ scanf */
			if (choice == 0)
			{
				printf("Bye!\n");
			}
			else if (choice < 0 || choice > 4)
			{
				printf("Invalid choice\n");
			}
		} /* 3. إغلاق قوس الـ scanf هنا بعد ما خلصنا الشروط */

	} while (choice != 0); /* 4. نهاية اللوب */

	return (0);
}
