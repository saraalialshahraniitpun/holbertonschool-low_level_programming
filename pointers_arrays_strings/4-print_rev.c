#include "main.h"

/**
 * print_rev - Prints a string in reverse, followed by a new line
 * @s: The string to print in reverse
 */
void print_rev(char *s)
{
	int len = 0;

	/* حساب طول السلسلة النصية للوصول إلى نهايتها */
	while (s[len] != '\0')
	{
		len++;
	}

	/* الرجوع للخلف وطباعة الحروف بالعكس */
	len--;
	while (len >= 0)
	{
		_putchar(s[len]);
		len--;
	}
	_putchar('\n');
}
