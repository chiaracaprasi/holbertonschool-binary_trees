#include "binary_trees.h"
#include <limits.h>

/**
 * isBSTUtil - returns true if the given tree is a binary search tree
 * @node: pointer to root node to check
 * @min: pointer to root node to check
 * @max: pointer to root node to check
 * Return: 1 if tree is a valid BST otherwise 0 (inc if tree NULL)
 */

int isBSTUtil(const binary_tree_t *node, int min, int max)
{
	if (node == NULL)
		return (1);

	if (node->n < min || node->n > max)
		return (0);

	return
		(isBSTUtil(node->left, min, node->n - 1) &&
		 isBSTUtil(node->right, node->n + 1, max));
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to root node to check
 * Return: 1 if tree is a valid BST otherwise 0 (inc if tree NULL)
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{

	if (tree == NULL)
		return (0);

	return (isBSTUtil(tree, INT_MIN, INT_MAX));

}
