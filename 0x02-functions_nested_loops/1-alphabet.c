#include "main.h"

/**
 * main - prints the alphabet
 * Description: print the alphabet in lower case
 * Return: Always (Success)
 */
main print_alphabet(void)
{
	char c;

	for (c = 'a'; c <= 'z'; c++)
		_putchar(c);
	_putchar('\n');
}
