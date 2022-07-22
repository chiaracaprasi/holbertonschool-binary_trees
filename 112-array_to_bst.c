#include "binary_trees.h"

/**
 * array_to_bst - convert an array to binary search tree
 * @array: a pointer to the 1st element of the array
 * @size: number of the element in the array
 * Return: a pointer to the root node of the BST
 */
bst_t *array_to_bst(int *array, size_t size)
{
	binary_tree_t *root = NULL;
	size_t i;

	if (array == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		bst_insert(&root, array[i]);

	return (root);
}
