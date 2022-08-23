#include "binary_trees.h"

/**
 * binary_tree_inorder - Traverse through binary tree using in-order traversal
 *
 * @tree: Pointer to root node of the tree to traverse
 * @func: Pointer to function to call for each node(Value)
 *
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{

	if (tree == NULL || func == NULL)
		return;
	if (tree->left != NULL)
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
	if (tree->left == NULL)
		func(tree->n);
}
