#include "binary_trees.h"

/**
 * find_lowestCommonAncestor - find the lowest ancestor in given binary tree
 * @root: pointer to the root
 * @a: given node a
 * @b: given node b
 * Return: the lowest common ancestor
 */
binary_tree_t *find_lowestCommonAncestor(binary_tree_t *root,
										const binary_tree_t *a, const binary_tree_t *b)
{
	binary_tree_t *left;
	binary_tree_t *right;

	if (root == NULL || root == a || root == b)
		return (root);
	left = find_lowestCommonAncestor(root->left, a, b);
	right = find_lowestCommonAncestor(root->right, a, b);
	if (left == NULL)
		return (right);
	else if (right == NULL)
		return (left);
	else
		return (root);
}
/**
 * binary_trees_ancestor - find the lowest common ancestor of two given nodes
 * @first: pointer to first node
 * @second: pointer to second node
 * Return: pointer to lowest common ancestor node, NUll if not found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									const binary_tree_t *second)
{
	binary_tree_t *root_1 = (binary_tree_t *)first;
	binary_tree_t *root_2 = (binary_tree_t *)second;

	if (first == NULL || second == NULL)
		return (NULL);
	while (root_1->parent != NULL)
		root_1 = root_1->parent;
	while (root_2->parent != NULL)
		root_2 = root_2->parent;
	if (root_1 != root_2)
		return (NULL);
	return (find_lowestCommonAncestor(root_1, first, second));
}
