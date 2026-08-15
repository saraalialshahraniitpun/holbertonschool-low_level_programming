#include <stdlib.h>
#include <string.h>
#include "store.h"

/**
 * store_init - Initializes the store structure.
 * @st: Pointer to the store to initialize.
 */
void store_init(store_t *st)
{
	if (st == NULL)
		return;

	st->head = NULL;
}

/**
 * store_add - Adds a session to the store.
 * @st: Pointer to the store.
 * @s: Pointer to the session to add.
 *
 * Return: 1 on success, 0 on failure.
 */
int store_add(store_t *st, session_t *s)
{
	node_t *new_node;

	if (st == NULL || s == NULL || s->id == NULL)
	{
		if (s != NULL)
			session_destroy(s);
		return (0);
	}

	/* إذا كان ID مكرر، نقوم بتدمير الجلسة لحمايتها من التسريب وإرجاع 0 */
	if (store_get(st, s->id) != NULL)
	{
		session_destroy(s);
		return (0);
	}

	new_node = malloc(sizeof(node_t));
	if (new_node == NULL)
	{
		session_destroy(s);
		return (0);
	}

	new_node->sess = s;
	new_node->next = st->head;
	st->head = new_node;

	return (1);
}

/**
 * store_get - Retrieves a session by its ID.
 * @st: Pointer to the store.
 * @id: Session ID to search for.
 *
 * Return: Pointer to session_t if found, NULL otherwise.
 */
session_t *store_get(store_t *st, const char *id)
{
	node_t *curr;

	if (st == NULL || id == NULL)
		return (NULL);

	curr = st->head;
	while (curr != NULL)
	{
		if (curr->sess != NULL && curr->sess->id != NULL)
		{
			if (strcmp(curr->sess->id, id) == 0)
				return (curr->sess);
		}
		curr = curr->next;
	}

	return (NULL);
}

/**
 * store_delete - Deletes a session by ID.
 * @st: Pointer to the store.
 * @id: Session ID to delete.
 * @out: Pointer to store deleted session if not destroyed.
 *
 * Return: 1 if deleted, 0 if not found or invalid input.
 */
int store_delete(store_t *st, const char *id, session_t **out)
{
	node_t *curr, *prev;

	if (st == NULL || id == NULL)
		return (0);

	curr = st->head;
	prev = NULL;

	while (curr != NULL)
	{
		if (curr->sess != NULL && curr->sess->id != NULL &&
		    strcmp(curr->sess->id, id) == 0)
		{
			if (prev == NULL)
				st->head = curr->next;
			else
				prev->next = curr->next;

			if (out != NULL)
				*out = curr->sess;
			else
				session_destroy(curr->sess);

			free(curr);
			return (1);
		}
		prev = curr;
		curr = curr->next;
	}

	return (0);
}

/**
 * store_destroy - Frees all allocated memory for store nodes and sessions.
 * @st: Pointer to the store.
 */
void store_destroy(store_t *st)
{
	node_t *curr, *temp;

	if (st == NULL)
		return;

	curr = st->head;
	while (curr != NULL)
	{
		temp = curr->next;
		if (curr->sess != NULL)
			session_destroy(curr->sess);
		free(curr);
		curr = temp;
	}

	st->head = NULL;
}
