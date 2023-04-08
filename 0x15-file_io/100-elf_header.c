#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include "main.h"

/**
 * main - Entry point
 *
 * @argc: argument count
 * @argv: command line arguments
 *
 * Description: a program to display information from an ELF header
 *		USAGE: elf_header elf_filename
 *		DISPLAYED INFO: magic, class, data, version, OS/ABI
 *				ABI version, type, entry point address
 *		FORMAT: same as readelf -h
 *		lseek can be used only once
 *		read can be used a maximum of 2 times at runtime
 *		printf is allowed
 *
 * Return: 0 (success), if file is not ELF, exit with status of 98
 */
void print_error(char* message)
{
    fprintf(stderr, "%s\n", message);
    exit(98);
}

void print_elf_header(Elf64_Ehdr* elf_header)
{
    printf("ELF Header:\n");
    printf("  Magic:   ");

    for (int i = 0; i < EI_NIDENT; i++)
    {
        printf("%02x ", elf_header->e_ident[i]);
    }
    printf("\n");
    printf("  Class:                             %s\n",
           elf_header->e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" :
           elf_header->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "invalid");
    printf("  Data:                              %s\n",
           elf_header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" :
           elf_header->e_ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big endian" : "invalid");
    printf("  Version:                           %d\n", elf_header->e_ident[EI_VERSION]);
    printf("  OS/ABI:                            ");
    switch (elf_header->e_ident[EI_OSABI])
    {
        case ELFOSABI_SYSV: printf("UNIX System V ABI\n"); break;
        case ELFOSABI_HPUX: printf("HP-UX ABI\n"); break;
        case ELFOSABI_NETBSD: printf("NetBSD ABI\n"); break;
        case ELFOSABI_LINUX: printf("Linux ABI\n"); break;
        case ELFOSABI_SOLARIS: printf("Solaris ABI\n"); break;
        case ELFOSABI_IRIX: printf("IRIX ABI\n"); break;
        case ELFOSABI_FREEBSD: printf("FreeBSD ABI\n"); break;
        case ELFOSABI_TRU64: printf("TRU64 UNIX ABI\n"); break;
        case ELFOSABI_ARM: printf("ARM architecture ABI\n"); break;
        case ELFOSABI_STANDALONE: printf("Standalone (embedded) ABI\n"); break;
        default: printf("Unknown\n"); break;
    }
    printf("  ABI Version:                       %d\n", elf_header->e_ident[EI_ABIVERSION]);
    printf("  Type:                              ");
    switch (elf_header->e_type)
    {
        case ET_NONE: printf("NONE (Unknown type)\n"); break;
        case ET_REL: printf("REL (Relocatable file)\n"); break;
        case ET_EXEC: printf("EXEC (Executable file)\n"); break;
        case ET_DYN: printf("DYN (Shared object file)\n"); break;
        case ET_CORE: printf("CORE (Core file)\n"); break;
        default: printf("Unknown\n"); break;
    }
    printf("  Entry point address:               0x%lx\n", elf_header->e_entry);
}

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        print_error("Usage: elf_header elf_filename");
    }
    int fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {

        print_error("Unable to open file");
    }
    Elf64_Ehdr elf_header;
    if (read(fd, &elf_header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
        print_error("Unable to read ELF header");
}
