#include "binary_trees.h"

/**
 * bst_insert - insert a value in binary search tree
 * @tree: double pointer to the root node of the BST to insert
 * @value: value of the node to insert
 * Return: return the pointer to the new inserted node
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
		return (*tree = binary_tree_node(*tree, value));
	if (value < (*tree)->n)
	{
		if ((*tree)->left != NULL)
			return (bst_insert(&((*tree)->left), value));
		(*tree)->left = binary_tree_node(*tree, value);
		return ((*tree)->left);
	}
	else if (value > (*tree)->n)
	{
		if ((*tree)->right != NULL)
			return (bst_insert(&((*tree)->right), value));
		(*tree)->right = binary_tree_node(*tree, value);
		return ((*tree)->right);
	}
	else
		return (NULL);
}
