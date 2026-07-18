#include "main.h"

/**
 * _atoi - converts a string to an integer.
 * @s: the string to be converted.
 *
 * Return: the integer value of the converted string.
 */
int _atoi(char *s)
{
	int sign = 1;
	int res = 0;
	int started = 0;

	while (*s)
	{
		if (*s == '-')
		{
			sign *= -1;
		}
		else if (*s == '+')
		{
			/* الإشارة الموجبة لا تغير القيمة الحالية لـ sign */
		}
		else if (*s >= '0' && *s <= '9')
		{
			started = 1;
			/* نقوم ببناء الرقم كقيمة سالبة لتجنب الـ signed-integer-overflow */
			res = (res * 10) - (*s - '0');
		}
		else if (started)
		{
			/* إذا مررنا على أرقام ثم جاء حرف غير رقمي، نتوقف فوراً */
			break;
		}
		s++;
	}

	/* إذا كانت الإشارة النهائية موجبة، نعكس الرقم السالب ليصبح موجباً */
	if (sign > 0)
	{
		res = -res;
	}

	return (res);
}
