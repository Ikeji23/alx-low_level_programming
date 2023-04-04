#include "lists.h"
#include <stdlib.h>

/**
 * free_listint2 - Frees a listint_t list and sets head to NULL
 *
 * @head: Pointer to a pointer to the head node of the list to be freed
 *
 * Return: void
 */
void free_listint2(listint_t **head)
{
    listint_t *current;

    if (head == NULL)
        return;

    while (*head != NULL)
    {
        current = *head;
        *head = (*head)->next;
        free(current);
    }

    *head = NULL;
}
