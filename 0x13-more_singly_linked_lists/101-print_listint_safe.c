#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_listint_safe - Prints a listint_t linked list
 *
 * @head: Pointer to the first node of the list
 *
 * Return: Number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	const listint_t *slow_ptr = head, *fast_ptr = head;

	while (slow_ptr && fast_ptr && fast_ptr->next)
	{
		printf("[%p] %d\n", (void *) slow_ptr, slow_ptr->n);
		count++;

		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next->next;

		if (slow_ptr == fast_ptr)
		{
			slow_ptr = head;
			while (slow_ptr != fast_ptr)
			{
				printf("[%p] %d\n", (void *) slow_ptr, slow_ptr->n);
				count++;
				slow_ptr = slow_ptr->next;
				fast_ptr = fast_ptr->next;
			}
			printf("[%p] %d\n", (void *) slow_ptr, slow_ptr->n);
			count++;
			break;
		}
	}

	if (!slow_ptr || !fast_ptr)
	{
		while (head)
		{
			printf("[%p] %d\n", (void *) head, head->n);
			count++;
			head = head->next;
		}
	}
	return (count);
}
