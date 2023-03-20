#include <stdlib.h>
#include <string.h>
#include "dog.h"

typedef struct dog dog_t;

/**
 * Creates a new dog with the given name, age, and owner.
 * Returns a pointer to the new dog.
 */
dog_t *new_dog(char *name, float age, char *owner) 
{
    // Allocate memory for the new dog
    dog_t *d = malloc(sizeof(dog_t));
    if (d == NULL) 
    {
        return NULL;
    }
    
    // Allocate memory for the name and copy it
    d->name = malloc(strlen(name) + 1);
    if (d->name == NULL) 
    {
        free(d);
        return NULL;
    }
    strcpy(d->name, name);
    
    // Allocate memory for the owner and copy it
    d->owner = malloc(strlen(owner) + 1);
    if (d->owner == NULL) 
    {
        free(d->name);
        free(d);
        return NULL;
    }
    strcpy(d->owner, owner);
    
    // Set the age
    d->age = age;
    
    return d;
}

