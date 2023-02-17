#include <stdio.h>

/**
 * main - entry point 
 * Description: Print numbers 0 to 9
 * Retrun: 0 (success)
 */
int main(void)
{
	int num;

	for (num = 0; num <= 9; num++)
		printf("%d", num);
	printf("\n");
	return (0);
}
