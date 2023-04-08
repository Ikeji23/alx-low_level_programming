#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include "main.h"

/**
 * main - displays the information contained in the ELF header
 * @argc: the number of arguments passed to the program
 * @argv: an array of pointers to the arguments passed to the program
 *
 * Return: 0 if successful, otherwise 98 if an error occurred
 */
int main(int argc, char *argv[])
{
Elf64_Ehdr header; / ELF header structure /
int file; / file descriptor for the ELF file /
ssize_t bytes_read; / number of bytes read by read /
unsigned int i; / loop index */

/* Check number of arguments */
if (argc != 2)
{
dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
exit(98);
}

/* Open the ELF file */
file = open(argv[1], O_RDONLY);
if (file == -1)
{
dprintf(STDERR_FILENO, "Error: Cannot read file '%s'.\n", argv[1]);
exit(98);
}

/* Read the ELF header */
bytes_read = read(file, &header, sizeof(header));
if (bytes_read != sizeof(header))
{
dprintf(STDERR_FILENO, "Error: Cannot read ELF header from file '%s'.\n", argv[1]);
exit(98);
}

/* Verify that the file is an ELF file */
for (i = 0; i < EI_NIDENT; i++)
{
if (i == 4)
printf("%c", header.e_ident[i]);
else
printf("%.2x ", header.e_ident[i]);
}
if (memcmp(header.e_ident, ELFMAG, SELFMAG) != 0)
{
printf("\nThis is not an ELF file\n");
exit(98);
}
else
printf("\n %-35s%-5hd %-26s\n", "Class:", header.e_ident[EI_CLASS], (header.e_ident[EI_CLASS] == ELFCLASS32) ? "ELF32" : "ELF64");

/* Print the rest of the information */
printf(" %-35s%-5s %-26s\n", "Data:", (header.e_ident[EI_DATA] == ELFDATA2LSB) ? "2's complement, little endian" : "2's complement, big endian", "");
printf(" %-35s%-5d %-26s\n", "Version:", header.e_ident[EI_VERSION], "");
printf(" %-35s%-5d %-26s\n", "OS/ABI:", header.e_ident[EI_OSABI], "");
printf(" %-35s%-5d %-26s\n", "ABI Version:", header.e_ident[EI_ABIVERSION], "");
printf(" %-35s%-5hd %-26s\n", "Type:", header.e_type, "");
printf(" %-35s%#lx %-26s\n", "Entry point address:", header.e_entry, "");

/* Close the file descriptor */
if (close(file) == -1)
{
dprintf(STDERR_FILENO, "Error: Cannot close file descriptor %d.\n", file);
exit(98);
}

return (0);
}
