#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - Adds a new node at the end of a list_t list.
 * @head: Double pointer to the head of the list_t list.
 * @str: String to be added to the new node.
 *
 * Return: Address of the new element, or NULL if it failed.
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new, *temp;
	char *dup_str;
	unsigned int len = 0;

	if (head == NULL)
		return (NULL);

	if (str != NULL)
	{
		dup_str = strdup(str);
		if (dup_str == NULL)
			return (NULL);
		while (str[len] != '\0')
			len++;
	}
	else
	{
		dup_str = NULL;
		len = 0;
	}

	new = malloc(sizeof(list_t));
	if (new == NULL)
	{
		free(dup_str);
		return (NULL);
	}

	new->str = dup_str;
	new->len = len;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
	}
	else
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (new);
}
