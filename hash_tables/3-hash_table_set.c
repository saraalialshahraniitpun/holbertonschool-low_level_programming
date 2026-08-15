#include "hash_tables.h"

/**
 * create_node - Creates a new hash node.
 * @key: Key for the node.
 * @value: Value associated with the key.
 *
 * Return: Pointer to the new node, or NULL on failure.
 */
hash_node_t *create_node(const char *key, const char *value)
{
	hash_node_t *new_node;

	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (NULL);

	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->value = strdup(value);
	if (new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node);
		return (NULL);
	}

	new_node->next = NULL;
	return (new_node);
}

/**
 * hash_table_set - Adds or updates an element in a hash table.
 * @ht: Pointer to the hash table.
 * @key: The key (cannot be empty string or NULL).
 * @value: The value associated with the key.
 *
 * Return: 1 if succeeded, 0 otherwise.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new_node, *temp;
	char *value_copy;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	temp = ht->array[index];

	while (temp != NULL)
	{
		if (strcmp(temp->key, key) == 0)
		{
			value_copy = strdup(value);
			if (value_copy == NULL)
				return (0);
			free(temp->value);
			temp->value = value_copy;
			return (1);
		}
		temp = temp->next;
	}

	new_node = create_node(key, value);
	if (new_node == NULL)
		return (0);

	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}
