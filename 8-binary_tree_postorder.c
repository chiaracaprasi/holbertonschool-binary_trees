#include "binary_trees.h"

/**
 * binary_tree_postorder - goes through a binary tree using postorder traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to function to call each node.
 * Value in the node must be passed as parameter to this function.
 * If tree or func is NULL do nothing
 *
 * Return: void
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
