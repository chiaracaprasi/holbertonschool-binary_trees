#include "binary_trees.h"

/**
 * binary_tree_height - to get the height of the binary tree
 * @tree: pointer to the root node
 * Return: the height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height > right_height)
		return (left_height + 1);

	return (right_height + 1);
}

/**
 * binary_tree_is_perfect - checks if a bianry treee is perfect
 * @tree: pointer to root node of the tree to count the number of leaves
 *
 * Return: 1 SUCCESS, otherwise 0 (incl if tree is NULL)
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	binary_tree_t *r = tree->right, *l = tree->left;

	if (tree == NULL)
		return (0);

	if (binary_tree_height(l) != binary_tree_height(r))
		return (0);

	if (l == NULL && r == NULL)
		return (1);

	if (l == NULL || r == NULL)
		return (0);

	if (binary_tree_is_perfect(l) && binary_tree_is_perfect(r))
		return (1);

	return (0);
}
