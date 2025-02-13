#include "binary_trees.h"

/**
 * binary_tree_nodes - count the nodes with at least 1 child in a binary tree
 * @tree: pointer to the root node
 * Return: the number of the nodes
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (0);
	return (binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right) + 1);
}
