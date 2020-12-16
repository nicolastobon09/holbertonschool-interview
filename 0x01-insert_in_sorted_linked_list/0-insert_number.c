#include "lists.h"

/**
 * insert_node - is a function that insert a node
 * @head: is a pointer
 * @number: is a number to insert
 * Return: new node or null if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{

	listint_t *new, *current;

	current = *head;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = number;
	new->next = NULL;

	if (*head == NULL)
		return(*head = new);

	while (current)
	{
		if (!current->next || current->next->n >= number)
		{
			new->next = current->next;
			current->next = new;
			return (new);
		}
		current = current->next;
	}
	return (NULL);
}
