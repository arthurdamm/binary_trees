#include "binary_trees.h"

/**
 * _binary_tree_height - helper func for binary_tree_height
 * @tree: input tree
 * Return: height of tree
 */
size_t _binary_tree_height(const binary_tree_t *tree)
{
	size_t a, b;

	if (!tree)
		return (0);

	a = _binary_tree_height(tree->left);
	b = _binary_tree_height(tree->right);
	return (MAX(a, b) + 1);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: input tree
 * Return: balance factor of descendants
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int a, b;

	if (!tree)
		return (0);
	a = (tree->left)
		? (int)_binary_tree_height(tree->left)
		: 0;
	b = (tree->right)
		? (int)_binary_tree_height(tree->right)
		: 0;
	return (a - b);
}

_Bool is_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (true);
	if (tree->n < min || tree->n > max)
		return (false);
	return (is_bst(tree->left, min, tree->n - 1) &&
		is_bst(tree->right, tree->n + 1, max));
}

/**
 * _binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to root of tree
 * Return: 1 if true 0 if false
 */
int _binary_tree_is_avl(const binary_tree_t *tree)
{
	int b;

	if (!tree)
		return (1);
	b = binary_tree_balance(tree);
	if (abs(b) > 1)
		return (0);
	return (_binary_tree_is_avl(tree->left) && _binary_tree_is_avl(tree->right));
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to root of tree
 * Return: 1 if true 0 if false
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (_binary_tree_is_avl(tree));
}
