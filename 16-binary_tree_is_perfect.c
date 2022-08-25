#include "binary_trees.h"

/**
 * tree_size - Measures the size of the tree
 * @tree: Pointer to binary tree
 * @ptr: Pointer to size
 */
void tree_size(const binary_tree_t *tree, size_t *ptr)
{
	if (tree == NULL)
		return;
	(*ptr)++;
	tree_size(tree->left, ptr);
	tree_size(tree->right, ptr);
}

/**
 * tree_height - Measures the height of binary tree
 * @tree: Pointer to binary tree
 * @ptr: Pointer to height
 */
void tree_height(const binary_tree_t *tree, size_t *ptr)
{
	size_t tmp = 0;

	if (tree->left != NULL || tree->right != NULL)
		(*ptr)++;
	if (tree->left != NULL && tree->right != NULL)
	{
		tmp = *ptr;
		tree_height(tree->left, ptr);
		tree_height(tree->right, &tmp);
	}
	else if (tree->left == NULL && tree->right != NULL)
		tree_height(tree->right, ptr);
	else if (tree->left != NULL && tree->right == NULL)
		tree_height(tree->left, ptr);
	if (tmp > *ptr)
		*ptr = tmp;
}

/**
 * _pow - Calculates the exponent
 * @a: First number passed
 * @b: Second number passed
 *
 * Return: a ^ b
 *
 */
size_t _pow(size_t a, size_t b)
{
	size_t i = 0, result = 1;

	if (b == 0)
		return (1);
	while (i < b)
		result *= a, i++;
	return (result);
}

/**
 * binary_tree_is_perfect - Check if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 - If binary tree is perfect
 *         0 - If tree is NULL or binary tree is not perfect
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height = 0, size = 0, max_size;

	if (tree == NULL)
		return (0);
	tree_size(tree, &size);
	tree_height(tree, &height);
	max_size = _pow(2, height + 1) - 1;
	return ((size == max_size) ? 1 : 0);
}
