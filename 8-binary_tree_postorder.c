#include "binary_trees.h"

/**
 * binary_tree_postorder - Traverse through binary tree
 * using post-order traversal
 *
 * @tree: Pointer to root node of the tree to traverse
 * @func: Pointer to function to call for each node(value)
 *
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	if (tree->left != NULL)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
	if (tree->left == NULL)
		func(tree->n);
}
