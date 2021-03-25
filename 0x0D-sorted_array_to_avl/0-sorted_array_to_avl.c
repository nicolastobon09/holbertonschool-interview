#include "binary_trees.h"

/**
 * create_node - function that create a node
 * @root: is node root
 * @value: is a int
 * Return: node
 */
avl_t *create_node(avl_t *root, int value)
{
	avl_t *node;

	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);

	node->parent = root;
	node->right = NULL;
	node->left = NULL;
	node->n = value;

	return (node);
}
/**
 * binary_AVL - fuction that insert a node
 * @parent: is a root
 * @array: is a array that contains a numbers
 * @start: is a index
 * @end: end to array
 * Return: node
 */
avl_t *binary_AVL(avl_t *parent, int *array, int start, int end)
{
	size_t middle;
	avl_t *root = NULL;

	if (start > end)
		return (NULL);

	middle = (start + end) / 2;

	root = create_node(parent, array[middle]);
	if (!root)
		return (NULL);

	root->left = binary_AVL(root, array, start, middle - 1);
	root->right = binary_AVL(root, array, middle + 1, end);
	return (root);
}
/**
 * sorted_array_to_avl - fuction that insert a node
 * @array: is a array that contains a numbers
 * @size: is a len of array
 * Return: a binary tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array)
		return (NULL);
	return (binary_AVL(NULL, array, 0, (int)size - 1));
}
