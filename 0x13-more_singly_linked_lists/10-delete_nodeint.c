#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes a node at a given index in a list
 *
 * @head: Pointer to a pointer to the head node of the list
 * @index: Index of the node to be deleted
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
    listint_t *current, *prev;
    unsigned int i;

    if (head == NULL || *head == NULL)
        return (-1);

    current = *head;

    if (index == 0)
    {
        *head = (*head)->next;
        free(current);
        return (1);
    }

    for (i = 0; i < index && current != NULL; i++)
    {
        prev = current;
        current = current->next;
    }

    if (current == NULL)
        return (-1);

    prev->next = current->next;
    free(current);

    return (1);
}
