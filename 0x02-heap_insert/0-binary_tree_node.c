#include "binary_trees.h"

/**
 * binary_tree_node - Function that creates a binary tree node
 * @parent: Is a pointer node of the node to create
 * @value: Is the value to put in the new node
 * Return: The new node or NULL on failure
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);

	new->parent = parent;
	new->n = value;
	new->left = NULL;
	new->right = NULL;

	return (new);
}
