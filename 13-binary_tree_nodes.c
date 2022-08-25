#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes in a binary tree
 *
 * @tree: Pointer to the root node of the tree to count the number of nodes
 *
 * Return: Number of nodes
 *         0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL || tree->right != NULL)
		nodes++;
	nodes += binary_tree_nodes(tree->right);
	nodes += binary_tree_nodes(tree->left);
	return (nodes);
}
