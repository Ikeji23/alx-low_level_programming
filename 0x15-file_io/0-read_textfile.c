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
	int fd;
	char *buffer;
	ssize_t read_count, write_count;

	if (!filename)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buffer = (char *) malloc(letters);
	if (!buffer)
	{
		close(fd);
		return (0);
	}
	ssize_t bytes_read = read(fd, buffer, letters);
	if (bytes_read == -1 || bytes_read != write(STDOUT_FILENO,
				buffer, bytes_read))

	{
		free(buffer);
		close(fd);
		return (0);
	}

	free(buffer);
	close(fd);
	return (bytes_read);
}

