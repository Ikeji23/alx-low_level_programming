#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "main.h"

#define BUFFER_SIZE 1024

/**
 * print_error - prints the error message to the standard error
 * @error_code: error code to print
 * @file_name: file name associated with the error
 **/
void print_error(int error_code, char *file_name)
{
	switch (error_code)
	{
		case 97:
			dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
			break;
		case 98:
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_name);
			break;
		case 99:
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_name);
			break;
		case 100:
			dprintf(STDERR_FILENO, "Error: Can't close fd %s\n", file_name);
			break;
		default:
			break;
	}
}

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 97-100 on failure
 **/
int main(int argc, char **argv)
{
	int fd_from, fd_to, bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
	{
		print_error(97, NULL);
		return (97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		print_error(98, argv[1]);
		return (98);
	}

	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd_to == -1)
	{
		print_error(99, argv[2]);
		close(fd_from);
		return (99);
	}

	do {
		bytes_read = read(fd_from, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			print_error(98, argv[1]);
			close(fd_from);
			close(fd_to);
			return (98);
		}

		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1)
		{
			print_error(99, argv[2]);
			close(fd_from);
			close(fd_to);
			return (99);
		}
	} while (bytes_read > 0);

	if (close(fd_from) == -1)
	{
		print_error(100, argv[1]);
		close(fd_to);
		return (100);
	}

	if (close(fd_to) == -1)
	{
		print_error(100, argv[2]);
		return (100);
	}

	return (0);
}
