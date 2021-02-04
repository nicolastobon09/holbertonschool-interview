#include "lists.h"


/**
 * check_cycle - function that checks if a singly linked list has a cycle in it
 * @list: is a pointer to a linked list
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *currrent = list;
	listint_t *tmp = list;

	if (!list)
		return (0);

	while (currrent)
	{
		if (tmp == currrent->next)
			return (1);

		if(currrent->next)
			currrent = currrent->next->next;
		else
			currrent = currrent->next;

		tmp = tmp->next;
	}

	return (0);
}
