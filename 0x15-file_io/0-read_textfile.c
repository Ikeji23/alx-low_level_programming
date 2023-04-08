#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the
 * POSIX standard output
 *
 * @filename: file to read
 * @letters: number of letters to read and print
 *
 * Return: actual number of letters it could read and print, otherwise
 *		0 if file cannot be opened or read, @filename is NULL
 *		or if write fails or does not write the expected
 *		amount of bytes
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char *buffer;
	ssize_t read_count, write_count;

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (!buffer)
	{
		close(fd);
		return (0);
	}

	read_count = read(fd, buffer, letters);
	if (read_count == -1)
	{
		close(fd);
		free(buffer);
		return (0);
	}

	write_count = write(STDOUT_FILENO, buffer, read_count);
	if (write_count == -1 || (size_t)write_count != read_count)
	{
		close(fd);
		free(buffer);
		return (0);
	}

	close(fd);
	free(buffer);

	return (write_count);
}
