#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * @argc: argument count
 * @argv: arguments as array of strings
 *
 * Description: print the name of the program
 *
 * Return: 0 (success)
 */
int main(int __attribute__((unused)) argc, char *argv[])
{
	printf("%s\n", argv[0]);
	return (0);
}
