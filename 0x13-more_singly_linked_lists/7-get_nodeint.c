#include "lists.h"

/**
 * get_nodeint_at_index - Returns the nth node of a listint_t linked list
 *
 * @head: Pointer to the head node of the list
 * @index: Index of the node to be returned (starting at 0)
 *
 * Return: Pointer to the nth node, or NULL if the node does not exist
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
    unsigned int i;
    listint_t *current;

    if (head == NULL)
        return (NULL);

    current = head;
    for (i = 0; i < index; i++)
    {
        if (current == NULL)
            return (NULL);
        current = current->next;
    }

    return (current);
}
