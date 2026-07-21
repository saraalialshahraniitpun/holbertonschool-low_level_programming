#include <stdlib.h>
#include "dog.h"

/**
 * _strlen - Calculates the length of a string.
 * @str: The string to evaluate.
 *
 * Return: Length of the string.
 */
static int _strlen(char *str)
{
	int len = 0;

	while (str && str[len] != '\0')
		len++;

	return (len);
}

/**
 * _strcpy - Copies a string including the terminating null byte.
 * @dest: Destination buffer.
 * @src: Source string.
 *
 * Return: Pointer to dest.
 */
static char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * new_dog - Creates a new dog struct with copied strings.
 * @name: Name of the dog.
 * @age: Age of the dog.
 * @owner: Owner of the dog.
 *
 * Return: Pointer to the new dog struct, or NULL if allocation fails.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;
	int len1, len2;

	if (name == NULL || owner == NULL)
		return (NULL);

	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);

	len1 = _strlen(name);
	len2 = _strlen(owner);

	dog->name = malloc(sizeof(char) * (len1 + 1));
	if (dog->name == NULL)
	{
		free(dog);
		return (NULL);
	}

	dog->owner = malloc(sizeof(char) * (len2 + 1));
	if (dog->owner == NULL)
	{
		free(dog->name);
		free(dog);
		return (NULL);
	}

	_strcpy(dog->name, name);
	_strcpy(dog->owner, owner);
	dog->age = age;

	return (dog);
}
