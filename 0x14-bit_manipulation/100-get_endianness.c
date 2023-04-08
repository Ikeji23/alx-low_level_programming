#include "main.h"

/**
 * get_endianness - checks the endianness
 *
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	unsigned int test_num = 1;
	unsigned char *byte_ptr = (unsigned char *) &test_num;

	return (*byte_ptr == 1);
}
