#include "main.h"
#include <stdlib.h>

/**
 * free_words - Frees memory allocated for an array of strings.
 * @words: The array of strings to free.
 * @i: Number of elements to free.
 */
static void free_words(char **words, int i)
{
	while (i >= 0)
	{
		free(words[i]);
		i--;
	}
	free(words);
}

/**
 * count_words - Counts the number of words in a string.
 * @str: The string to evaluate.
 *
 * Return: Number of words.
 */
static int count_words(char *str)
{
	int count = 0, i = 0;

	while (str[i] != '\0')
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

/**
 * strtow - Splits a string into words.
 * @str: The string to split.
 *
 * Return: Pointer to array of strings (words), or NULL if failed.
 */
char **strtow(char *str)
{
	char **words;
	int i = 0, k = 0, len = 0, num_words, c;

	if (str == NULL || *str == '\0')
		return (NULL);

	num_words = count_words(str);
	if (num_words == 0)
		return (NULL);

	words = malloc(sizeof(char *) * (num_words + 1));
	if (words == NULL)
		return (NULL);

	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			len = 0;
			while (str[i + len] != ' ' && str[i + len] != '\0')
				len++;

			words[k] = malloc(sizeof(char) * (len + 1));
			if (words[k] == NULL)
			{
				free_words(words, k - 1);
				return (NULL);
			}

			for (c = 0; c < len; c++)
				words[k][c] = str[i + c];
			words[k][c] = '\0';
			k++;
			i += len;
		}
		else
			i++;
	}
	words[k] = NULL;
	return (words);
}
