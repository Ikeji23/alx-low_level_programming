#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * alloc_grid - create a multidimensional array initialized to 0
 *
 * @width: width of the array
 * @height: height of the array
 *
 * Return: pointer to the array, or NULL if negative dimensions provided
 */
int **alloc_grid(int width, int height)
{
	int **t;
	int i;
	int j;

	if (width <= 0 || height <= 0)
		return (NULL);

	t = (int **)malloc(sizeof(int *) * height);
	if (t == NULL)
		return (NULL);

	for (i = 0; i < height; i++)
	{
		t[i] = (int *)malloc(sizeof(int) * width);
		if (t[i] == NULL)
		{
			for (j = 0; j < i; j++)
			{
				free(t[j]);
			}
			free(t);
		}
	}

	for (i = 0; i < height; i++)
		for (j = 0; j < width; j++)
			t[i][j] = 0;

	return (t);
}
