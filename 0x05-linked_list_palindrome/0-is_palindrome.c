#include "lists.h"

/**
 * recursive_palindrome - checks if a singly linked list is a palindrome
 * @current: double pointer representing the first node in the list
 * @tmp: pointer that checks if the value of the node
 * is equal to the current value
 * Return: 1 if it is palindrome or 0 if it is no
 */
int recursive_palindrome(listint_t **current, listint_t *tmp)
{
	int check_value;

	if (!tmp || !current)
		return (1);

	check_value = recursive_palindrome(current, tmp->next);

	if (tmp->n == (*current)->n)
		(*current) = (*current)->next;
	else
		return (0);

	return (check_value);
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to pointer of first node of listint_t list
 * Return: 1 if a linked list is palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *current = *head;

	return (recursive_palindrome(&current, *head));
}
