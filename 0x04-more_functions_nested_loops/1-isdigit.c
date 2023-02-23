#include "main.h"
/**
 * _isupper - checks if a character is a digit
 * @c: The number to be checked to checked
 *
 * Return: gives 1 or 0
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}
