#include <stdlib.h>
#include <string.h>
#include "session.h"

/**
 * session_create - Creates a new session structure.
 * @id: Session string ID.
 * @uid: User ID.
 * @data: Pointer to raw binary data buffer.
 * @data_len: Length of the data buffer.
 *
 * Return: Pointer to allocated session_t, or NULL on failure.
 */
session_t *session_create(const char *id, unsigned int uid,
			  const unsigned char *data, size_t data_len)
{
	session_t *s;

	if (id == NULL)
		return (NULL);

	if (data == NULL && data_len > 0)
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

	s->uid = uid;
	s->data = NULL;
	s->data_len = 0;

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
		s->data_len = data_len;
	}

	return (s);
}

/**
 * session_set_data - Updates the data buffer of a session.
 * @s: Pointer to the session.
 * @data: Pointer to new data buffer.
 * @data_len: Length of new data buffer.
 *
 * Return: 1 on success, 0 on failure.
 */
int session_set_data(session_t *s, const unsigned char *data, size_t data_len)
{
	unsigned char *new_data = NULL;

	if (s == NULL)
		return (0);

	if ((data == NULL && data_len > 0) || (data != NULL && data_len == 0))
		return (0);

	if (data != NULL && data_len > 0)
	{
		new_data = malloc(data_len);
		if (new_data == NULL)
			return (0);
		memcpy(new_data, data, data_len);
	}

	free(s->data);
	s->data = new_data;
	s->data_len = (new_data != NULL) ? data_len : 0;

	return (1);
}

/**
 * session_destroy - Frees memory occupied by a session.
 * @s: Pointer to session to destroy.
 */
void session_destroy(session_t *s)
{
	if (s == NULL)
		return;

	if (s->id != NULL)
		free(s->id);

	if (s->data != NULL)
		free(s->data);

	free(s);
}
