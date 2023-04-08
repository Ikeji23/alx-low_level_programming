#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: name of the file to read
 * @letters: number of letters to read and print
 *
 * Return: actual number of letters it could read and print, otherwise 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	if (filename == NULL)
	{
		return (0);
	}

	int fd = open(filename, O_RDONLY);
	
	if (fd == -1)

	{
		return (0);
	}

	char *buff = malloc(letters);
	
	if (buff == NULL)

	{
		close(fd);
		return (0);
	}

	ssize_t nread = read(fd, buf, letters);
	
	 if (nread == -1)

	 {
		close(fd);
		free(buff);
		return (0);
	 }

	 ssize_t nwritten = write(STDOUT_FILENO, buf, nread);
	
	 if (nwritten == -1 || nwritten != nread)
	 {
		 close(fd);
		 free(buff);
		 return (0);
	 }
	 close(fd);
	 free(buff);

	 return nread;
}
