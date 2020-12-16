#include "lists.h"

/**
 * insert_node - is a function that insert a node
 * @head: is a pointer
 * @number: is a number to insert
 * Return: new node or null if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{

	listint_t *new, *current, *temp;

	current = *head;

	if(head == NULL)
		return (NULL);

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = number;
	new->next = NULL;

	if (*head == NULL)
		*head = new;

	while (current->next != NULL && current->next->n < new->n)
		current = current->next;
	temp = current->next;
	current->next = new;
	new->next = temp;

	return (new);
}
