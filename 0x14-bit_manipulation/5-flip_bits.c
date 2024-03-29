#include "main.h"

/**
 * flip_bits - returns the number of bits you would need to flip
 *             to get from one number to another
 * @n: first unsigned long int number
 * @m: second unsigned long int number
 *
 * Return: number of bits you would need to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int diff = n ^ m;
	unsigned int count = 0;

	for (; diff > 0; diff >>= 1)
		count += diff & 1;

	return count;
}
