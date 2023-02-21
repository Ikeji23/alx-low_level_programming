#include "main.h"

/**
 * print_alphabet - returns nothing
 *
 * _putchar - prints character
 *
 * Return: Always 0
 * */
void print_alphabet(void)
{
	char c;

	for (c = 'a'; c <= 'z'; c++)
	{
		_putchar(c);
	}
	_putchar('\n');
}
