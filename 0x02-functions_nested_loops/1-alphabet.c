#include <stdio.h>
#include "main.h"
#include "main.c"

/**
 * main - prints the alphabet
 * Description: print the alphabet in lower case
 * Return: always 0;
 *
 */
int main(void)
{
	char i;

	for (i = 'a'; i <= 'z'; i++)
	{
		_putchar(i);
	}
	_putchar('\n');
}
