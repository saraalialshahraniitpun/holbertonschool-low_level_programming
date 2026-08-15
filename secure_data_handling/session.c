#include "session.h"
#include <stdlib.h>
#include <string.h>

session_t *session_create(const char *id, int user_id, const unsigned char *data, size_t data_len)
{
	session_t *s;

	if (id == NULL)
		return (NULL);

	s = malloc(sizeof(session_t));
	if (s == NULL)
		return (NULL);

	s->id = strdup(id);
	if (s->id == NULL)
	{
		free(s);
		return (NULL);
	}

	s->user_id = user_id;
	s->data_len = data_len;

	if (data != NULL && data_len > 0)
	{
		s->data = malloc(data_len);
		if (s->data == NULL)
		{
			free(s->id);
			free(s);
			return (NULL);
		}
		memcpy(s->data, data, data_len);
	}
	else
	{
		s->data = NULL;
		s->data_len = 0;
	}

	return (s);
}

void session_clear_data(session_t *s)
{
	if (s == NULL || s->data == NULL)
		return;

	memset(s->data, 0, s->data_len);
	free(s->data);
	s->data = NULL;
	s->data_len = 0;
}

void session_destroy(session_t *s)
{
	if (s == NULL)
		return;

	session_clear_data(s);
	if (s->id != NULL)
		free(s->id);
	free(s);
}

int session_update_data(session_t *s, const unsigned char *data, size_t data_len)
{
	unsigned char *new_data = NULL;

	if (s == NULL)
		return (-1);

	if (data != NULL && data_len > 0)
	{
		new_data = malloc(data_len);
		if (new_data == NULL)
			return (-1);
		memcpy(new_data, data, data_len);
	}

	session_clear_data(s);
	s->data = new_data;
	s->data_len = (new_data != NULL) ? data_len : 0;

	return (0);
}
