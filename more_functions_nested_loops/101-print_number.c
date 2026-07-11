#include "main.h"

/**
 * print_number - Prints an integer using only _putchar
 * @n: The integer to print
 *
 * Return: void
 */
void print_number(int n)
{
	unsigned int num;

	/* التحقق مما إذا كان الرقم سالباً */
	if (n < 0)
	{
		_putchar('-');
		num = -n; /* تحويل آمن باستخدام unsigned int لمنع الـ Overflow */
	}
	else
	{
		num = n;
	}

	/* التفكيك والاستدعاء الذاتي لطباعة الخانات بالترتيب الصحيح */
	if (num / 10)
	{
		print_number(num / 10);
	}

	_putchar((num % 10) + '0');
}
