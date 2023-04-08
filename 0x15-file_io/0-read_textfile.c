#include <unistd.h>
#include <stdlib.h>
#include <stdio>
#include <fcntl.h>
#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to the
 * POSIX standard output
 *
 * @filename: File to read
 * @letters: Number of letters to read and write
 *
 * Retrun: Actual number of letters it could read and print, otherwise
 *		return 0 if the file cannot be read or opened, @filename
 * 		is NULL
 * 		or if write fails or does not write the expected amount
 * 		of bytes
 */ 		
ssize_t read_textfile(const char *filename, size_t letters);
{
	int fd, printed, wrote;
	char *buff;

	buff = malloc(letters);
	if (buff == NULL)
		return (0);
	if (filename == NULL)
		return (0);
	fd = open(filename, O_RDWR);
	if (fd == -1)
		return (0);
	printed = read(fd, buff, letters);
	if (printed == -1)
		return (0);
	wrote = write(STDOUT_FILENO, buff, printed);
	if (wrote == -1)
		return (0);
	if (close(fd) == -1)
		return (0);
	free(buff);
	return (printed);
}
