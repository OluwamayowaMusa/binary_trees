#include "binary_trees.h"

/**
 * subtree - Traverse the subtree
 * @tree: Pointer to root node of the tree
 * @func: Pointer to function to call for each node
 */
void subtree(const binary_tree_t *tree, void (*func)(int))
{
	if (tree->left != NULL)
		subtree(tree->left, func);
	if (tree->parent == NULL)
		return;
	if (tree->left == NULL)
		func(tree->n);
	func(tree->parent->n);
	func(tree->parent->right->n);
}

/**
 * binary_tree_inoder - Traverse through a binary tree using in-order traversal
 *
 * @tree: Pointer to root node of the tree to traverse
 * @func: Pointer to function to call for each node(Value)
 *
 */
void binary_tree_inoder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *tmp = NULL;

	if (tree == NULL || func == NULL)
		return;
	tmp = tree->left;
	tmp->parent = NULL;
	subtree(tmp, func);

	func(tree->n);

	tmp = tree->right;
	tmp->parent = NULL;
	subtree(tmp, func);
}
