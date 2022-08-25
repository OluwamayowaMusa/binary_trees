#include "binary_trees.h"

/**
 * check_full - Check if a binary tree is full
 * @tree: Pointer to root node of the tree to check
 * @ptr: Pointer to control variable
 */
void check_full(const binary_tree_t *tree, int *ptr)
{
	if (tree == NULL)
		return;
	if (tree->left == NULL && tree->right != NULL)
		*(ptr) *= 0;
	else if (tree->left != NULL && tree->right == NULL)
		*(ptr) *= 0;
	else if (tree->left != NULL && tree->right != NULL)
		*(ptr) *= 1;
	else if (tree->left == NULL && tree->right == NULL)
		*(ptr) *= 1;
	check_full(tree->left, ptr);
	check_full(tree->right, ptr);
}


/**
 * binary_tree_is_full - Check if a binary tree is full
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 - If binary tree is full
 *         0 - If tree is NULL or binary tree is not full
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int ctrl = 1;

	if (tree == NULL)
		return (0);
	check_full(tree, &ctrl);
	return (ctrl);
}
