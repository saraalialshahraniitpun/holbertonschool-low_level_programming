#include "store.h"
#include <stdlib.h>
#include <string.h>

store_t *store_create(size_t initial_capacity)
{
	store_t *st;

	if (initial_capacity == 0)
		initial_capacity = 4;

	st = malloc(sizeof(store_t));
	if (st == NULL)
		return (NULL);

	st->sessions = calloc(initial_capacity, sizeof(session_t *));
	if (st->sessions == NULL)
	{
		free(st);
		return (NULL);
	}

	st->capacity = initial_capacity;
	st->count = 0;
	return (st);
}

session_t *store_find(store_t *st, const char *id)
{
	size_t i;

	if (st == NULL || id == NULL || st->sessions == NULL)
		return (NULL);

	for (i = 0; i < st->count; i++)
	{
		if (st->sessions[i] != NULL && st->sessions[i]->id != NULL)
		{
			if (strcmp(st->sessions[i]->id, id) == 0)
				return (st->sessions[i]);
		}
	}
	return (NULL);
}

int store_insert(store_t *st, session_t *session)
{
	session_t **new_sessions;
	size_t new_capacity;

	if (st == NULL || session == NULL || session->id == NULL)
		return (-1);

	if (store_find(st, session->id) != NULL)
		return (-1);

	if (st->count >= st->capacity)
	{
		new_capacity = st->capacity * 2;
		new_sessions = realloc(st->sessions, new_capacity * sizeof(session_t *));
		if (new_sessions == NULL)
			return (-1);

		st->sessions = new_sessions;
		st->capacity = new_capacity;
	}

	st->sessions[st->count] = session;
	st->count++;
	return (0);
}

int store_delete(store_t *st, const char *id)
{
	size_t i, j;

	if (st == NULL || id == NULL || st->sessions == NULL)
		return (-1);

	for (i = 0; i < st->count; i++)
	{
		if (st->sessions[i] != NULL && st->sessions[i]->id != NULL)
		{
			if (strcmp(st->sessions[i]->id, id) == 0)
			{
				session_destroy(st->sessions[i]);
				for (j = i; j < st->count - 1; j++)
					st->sessions[j] = st->sessions[j + 1];
				st->sessions[st->count - 1] = NULL;
				st->count--;
				return (0);
			}
		}
	}
	return (-1);
}

void store_clear(store_t *st)
{
	size_t i;

	if (st == NULL || st->sessions == NULL)
		return;

	for (i = 0; i < st->count; i++)
	{
		if (st->sessions[i] != NULL)
		{
			session_destroy(st->sessions[i]);
			st->sessions[i] = NULL;
		}
	}
	st->count = 0;
}

void store_destroy(store_t *st)
{
	if (st == NULL)
		return;

	store_clear(st);
	if (st->sessions != NULL)
		free(st->sessions);
	free(st);
}
