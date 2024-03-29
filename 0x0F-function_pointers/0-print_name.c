#include "function_pointers.h"

/**
 * print_name - print the name
 *
 * @name: the name to print
 * @f: pointer to a function that accepts a string as argument
 * and returns void
 *
 */
void print_name(char *name, void (*f)(char *))
{
	if (name && f)
		f(name);
}
