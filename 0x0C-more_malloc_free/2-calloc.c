#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * _calloc - allocate memory for an array
 *
 * @nmemb: number of elements in the array
 * @size: size of the elements
 *
 * Description: set memory to zero
 *
 * Return: pointer to newly allocated array
 *	   NULL if @nmemb or @size are 0, or if malloc fails
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *t;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);
	t = malloc(nmemb * size);
	if (t == NULL)
		return (NULL);
	for (i = 0; i < nmemb * size; i++)
		t[i] = 0;

	return (t);
}
