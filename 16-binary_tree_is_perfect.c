#include "binary_trees.h"

/**
 * tree_height - Measures the height of a binary tree
 * @tree: Pointer to root node
 *
 * Return: Height of tree, 0 if NULL
 */
size_t tree_height(const binary_tree_t *tree)
{
	size_t left_h = 0, right_h = 0;

	if (tree == NULL)
		return (0);

	left_h = tree->left ? 1 + tree_height(tree->left) : 0;
	right_h = tree->right ? 1 + tree_height(tree->right) : 0;

	return (left_h > right_h ? left_h : right_h);
}

/**
 * tree_size - Measures the size of a binary tree
 * @tree: Pointer to root node
 *
 * Return: Size of tree, 0 if NULL
 */
size_t tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, 0 if NULL or not perfect
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height = 0, size = 0, expected_size = 0;

	if (tree == NULL)
		return (0);

	height = tree_height(tree);
	size = tree_size(tree);
	expected_size = (1 << (height + 1)) - 1;

	return (size == expected_size);
}
