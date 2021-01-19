#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to pointer of first node of listint_t list
 * Return: 1 if a linked list is palindrome
 */
int is_palindrome(listint_t **head)
{

	if (!head || !*head)
		return (1);

	listint_t *current = *head;
	int length;

	for (length = 0; current != NULL; length++)
		current = current->next;

	current = *head;
	int array[length];

	for (int value = 0; current != NULL; value++)
	{

		array[value] = current->n;
		current = current->next;
	}

	for (int j = 0; j < length; j++)
	{

		if (array[j] == array[length - 1])
			length--;
		else
			return (0);
	}

	return (1);
}
