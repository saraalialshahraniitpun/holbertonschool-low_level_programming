#ifndef DOG_H
#define DOG_H

/**
 * struct dog - Defines a dog's basic attributes.
 * @name: Name of the dog (string).
 * @age: Age of the dog (float).
 * @owner: Name of the dog's owner (string).
 *
 * Description: Header file defining a struct for a dog entity.
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

/**
 * dog_t - Typedef for struct dog
 */
typedef struct dog dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);
#endif /* DOG_H */
