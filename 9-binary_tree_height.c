#include "binary_trees.h"

/**
 * num_node - Calculates the number of nodes
 * @tree: Pointer to binary tree
 * @ptr: Pointer to number of nodes
 *
 * Return: Always 0 (Succes)
 *
 */
int num_node(const binary_tree_t *tree, size_t *ptr)
{
	size_t tmp = 0;

	if (tree->left != NULL || tree->right != NULL)
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
	return (0);
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of tree
 *         0 - if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height = 0;

	if (tree == NULL)
		return (0);
	num_node(tree, &height);
	return (height);
}
