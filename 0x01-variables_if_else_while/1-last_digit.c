#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * Main - Prints if number is greater than, zero or less than 6 and not 0
 *
 * Description: 'Last digit of'
 *
 * Return: 0 (Success)
 */
int main(Last digit)
{
	int n;
	int lastDigit;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	lastDigit = n % 10;
	printf("Last digit of %d is %d and is ", n, lastDigit);
	if (lastDigit > 5)
		printf("greater than 5\n");
	else if (lastDigit == 0)
		printf("0\n");
	else
		printf("less than 6 and not 0\n");
	return (0);
}

