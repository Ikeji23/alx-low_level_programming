#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t linked list
 *
 * @h: Pointer to the pointer to the head node of the list
 *
 * Return: The size of the list that was free'd
 *
 * Description: This function can free lists with a loop. It goes through the
 * list only once. The function sets the head to NULL.
 */
size_t free_listint_safe(listint_t **h)
{
    size_t size = 0;
    listint_t *current, *next;

    if (h == NULL || *h == NULL)
        return (0);

    current = *h;
    while (current != NULL)
    {
        size++;
        next = current->next;
        free(current);
        if (next >= current)
        {
            *h = NULL;
            exit(98);
        }
        current = next;
    }

    *h = NULL;
    return (size);
}
