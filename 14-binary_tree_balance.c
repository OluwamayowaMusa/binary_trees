#include "binary_trees.h"

/**
 * num_node - Calculates the height of the tree
 *
 * @tree: Pointer to the binary tree
 * @ptr: Pointer to the height
 *
 */
void num_node(const binary_tree_t *tree, int *ptr)
{
	int tmp = 0;

	if (tree == NULL)
		return;
	if (tree != NULL)
		(*ptr)++;
	if (tree->left != NULL && tree->right != NULL)
	{
		tmp = *ptr;
		num_node(tree->left, ptr);
		num_node(tree->right, &tmp);
	}
	else if (tree->left == NULL && tree->right != NULL)
		num_node(tree->right, ptr);
	else if (tree->left != NULL && tree->right == NULL)
		num_node(tree->left, ptr);
	if (tmp > *ptr)
		*(ptr) = tmp;
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 *
 * @tree: Pointer to the root nodde of the tree to measure the balance factor
 *
 * Return: Balance Factor
 *         0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int height_left = 0, height_right = 0;

	if (tree == NULL)
		return (0);
	num_node(tree->left, &height_left);
	num_node(tree->right, &height_right);
	return (height_left - height_right);
}
