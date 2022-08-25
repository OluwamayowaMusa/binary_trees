#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node
 *
 * @node: Pointer to node to find the sibling
 *
 * Return: Pointer to sibling node
 *         NULL - If node is NULL or parent is NULL
 *         NULL - if node has no sibling
 *
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	if (node->parent->right != NULL)
		return ((node->n == node->parent->right->n) ? node->parent->left :
				node->parent->right);
	return (NULL);
}
