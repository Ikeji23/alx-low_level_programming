#include <stdio.h>

/**
 * main - Entry point
 * Description: print numbers 0 to 9 using putchar()
 * Return: 0 (success)
 */
int main(void)
{
	int a = 0;

	for (; a < 10 ; a++)
		putchar('0' + a);
	putchar('\n');
	return (0);
}
