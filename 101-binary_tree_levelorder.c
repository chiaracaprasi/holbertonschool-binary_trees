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
 * binary_tree_level - call function on a specific level of binary tree
 * @tree: pointer to root of tree
 * @l: level of tree to perform a function on
 * @f: function to call
 *
 * Return: void
 */
void binary_tree_level(const binary_tree_t *tree, size_t l, void (*f)(int))
{
	if (tree == NULL)
		return;

	if (l == 1)
		f(tree->n);

	else if (l > 1)
	{
		binary_tree_level(tree->left, l - 1, f);
		binary_tree_level(tree->right, l - 1, f);
	}
}


/**
 * binary_tree_levelorder - goes through binary tree using levelorder traversal
 * @tree: pointer to root node of the tree to traverse
 * @func: pointer to a function to call for each node.
 * Return: void
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int h =  binary_tree_height(tree);
	int i;

	if (tree == NULL || func == NULL)
		return;

	for (i = 1; i <= h; i++)
		binary_tree_level(tree, i, func);

}
