#include <stdio.h>

/* تعريف البروتوتايب هنا مباشرة لضمان رؤية الكومبايلر له */
int _strlen(char *s);

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	char *str;
	int len;

	str = "My first strlen!";
	len = _strlen(str);
	printf("%d\n", len);
	return (0);
}
