#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left child of another node
 * @parent: Pointer to the node to insert the left child
 * @value: Value to store in node
 *
 * Return: Pointer to the created node
 *         NULL on failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node = NULL, *tmp = NULL;

	if (parent == NULL)
		return (NULL);
	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);
	node->parent = parent;
	node->n = value;
	node->right = NULL;
	node->left = NULL;
	if (parent->left == NULL)
	{
		parent->left = node;
	}
	else
	{
		tmp = parent->left;
		parent->left = node;
		node->left = tmp;
		tmp->parent = node;
	}
	return (node);
}
