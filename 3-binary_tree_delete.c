#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes an entire binary tree
 * @tree: Pointer to root node of the tree to delete
 *
 */
void binary_tree_delete(binary_tree_t *tree)
{
	binary_tree_t *tmp_right = NULL, *tmp_left = NULL;

	if (tree == NULL)
		return;
	tmp_right = tree->right;
	tmp_left = tree->left;
	free(tree);
	tree = NULL;
	binary_tree_delete(tmp_right);
	binary_tree_delete(tmp_left);
}
