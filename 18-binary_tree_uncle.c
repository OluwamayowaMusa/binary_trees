#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node
 * @node: Pointer to the node to find the uncle
 *
 * Return: Pointer to Uncle node
 *         NULL - If node is NULL or node has no Uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	if (node->parent->parent != NULL)
		return ((node->parent->n == node->parent->parent->right->n) ?
			node->parent->parent->left : node->parent->parent->right);
	return (NULL);
}
