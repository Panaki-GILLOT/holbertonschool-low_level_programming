#include "lists.h"
#include <stdlib.h>

/**
 * insert_dnodeint_at_index - Inserts a new node at a given index
 * @h: Pointer to the head of the list
 * @idx: Index where the new node should be added (starting at 0)
 * @n: Value to store in the new node
 *
 * Return: Address of the new node, or NULL if it fails
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *current;
	unsigned int i;

	if (!h)
		return (NULL);

	/* Insert at the beginning */
	if (idx == 0)
		return (add_dnodeint(h, n)); /* Assuming 2-add_dnodeint.c defines add_dnodeint */

	current = *h;
	i = 0;

	/* Traverse to the node just before the insertion point */
	while (current != NULL && i < idx - 1)
	{
		current = current->next;
		i++;
	}

	if (!current) /* Index is out of bounds */
		return (NULL);

	/* Insert at the end if current->next is NULL */
	if (!current->next)
		return (add_dnodeint_end(h, n)); /* Assuming 3-add_dnodeint_end.c defines add_dnodeint_end */

	/* Create new node */
	new_node = malloc(sizeof(dlistint_t));
	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->next = current->next;
	new_node->prev = current;

	current->next->prev = new_node;
	current->next = new_node;

	return (new_node);
}
