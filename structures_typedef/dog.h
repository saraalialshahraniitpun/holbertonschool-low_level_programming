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
void init_dog(struct dog *d, char *name, float age, char *owner);
#endif /* DOG_H */
