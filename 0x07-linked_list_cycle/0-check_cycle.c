#include "lists.h"


/**
 * check_cycle - function that checks if a singly linked list has a cycle in it
 * @list: is a pointer to a linked list
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *currrent = list;

	if (!list)
		return (0);

	while (currrent->next != list)
	{
		if (!currrent->next)
			return (0);
		currrent = currrent->next;
	}

	return (1);
}
