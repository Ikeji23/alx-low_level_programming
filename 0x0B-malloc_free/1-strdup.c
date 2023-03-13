#include <stdlib.h>
#include "main.h"

/**
 * _strdup - duplicate a string
 *
 * @str: the string to copy
 *
 * Return: pointer to the newly allocated space in memory,
 *	   NULL if @str is null, or insufficient memory available
 */
char *_strdup(char *str)
{
	int i;
	int c = 0;
	char *t;

	if (str == NULL)
		return (NULL);

	while (str[c] != '\0')
		c++;

	t = malloc(sizeof(char) * c + 1);

	if (t == NULL)
		return (NULL);

	for (i = 0; i < c; i++)
		t[i] = str[i];

	return (t);

}
