#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "main.h"

#define BUFFER_SIZE 1024

/**
 * main - Entry point
 *
 * @argc: argument count
 * @argv: command line arguments
 *
 * Description: - A program that copies the content of a file to another file.
 *		- Usage: cp file_from file_to
 *		- Permissions of the created file: rw-rw-r--.
 *		- If the file already exists, do not change the permissions
 *		- Use 1,024 bytes at a time from the file_from
 *		- dprintf is allowed to use
 *
 * Return: 0 (sucess), or exit with status of:
 *	97 - if argc is not correct,
 *	98 - if file_from does not exist or cannot be read from
 *	99 - if unable to create or if write to file_to fails
 *	100 - if unable to close the file descriptor
 *
 */
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
        exit(97);
    }

    int file_from = open(argv[1], O_RDONLY);
    if (file_from == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        exit(98);
    }

    int file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (file_to == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", argv[2]);
        exit(99);
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;
    while ((bytes_read = read(file_from, buffer, BUFFER_SIZE)) > 0)
    {
        ssize_t bytes_written = write(file_to, buffer, bytes_read);
        if (bytes_written != bytes_read)
        {
            dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", argv[2]);
            exit(99);
        }
    }

    if (bytes_read == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        exit(98);
    }

    if (close(file_from) == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
        exit(100);
    }

    if (close(file_to) == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to);
        exit(100);
    }

    exit(EXIT_SUCCESS);
}
