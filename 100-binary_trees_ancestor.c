#include "binary_trees.h"

/**
 * node_depth - Measures the depth of node
 * @node: Pointer to node of binary tree
 *
 * Return: Depth of node
 */
size_t node_depth(const binary_tree_t *node)
{
	size_t depth = 0;

	if (node == NULL || node->parent == NULL)
		return (0);
	depth++;
	depth += node_depth(node->parent);
	return (depth);
}

/**
 * binary_trees_ancestor - Finds the lowest common ancestor
 * @first: Pointer to first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node
 *         NULL - if no ancestor is found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const
		binary_tree_t *second)
{
	size_t depth_first, depth_second, ctrl;

	if (first == NULL || second == NULL)
		return (NULL);
	depth_first = node_depth(first);
	depth_second = node_depth(second);
	while (depth_first > depth_second)
		depth_first--, first = first->parent;
	while (depth_second > depth_first)
		depth_second--, second = second->parent;

	for (ctrl = 0; ctrl < depth_first + 1; ctrl++)
	{
		if (first == second)
		{
			return ((binary_tree_t *)first);
		}
		first = first->parent;
		second = second->parent;
	}
	return (NULL);
}
