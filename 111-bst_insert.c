#include "binary_trees.h"

bst_t *_bst_insert(bst_t **tree, int value, bst_t **ret)
{
	bst_t *l,*r;

	if (*tree == NULL)
	{
		l = binary_tree_node(*tree, value);
		*tree = l;
		*ret = l;
		return (l);
	}
	if ((*tree)->n > value)
	{
		l = _bst_insert(&((*tree)->left), value, ret);;
		(*tree)->left = l;
		l->parent= *tree;
	}
	else if ((*tree)->n < value)
	{
		r = _bst_insert(&((*tree)->right), value, ret);
		(*tree)->right = r;
		r->parent = *tree;
	}
	return(*tree);
}

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *l = NULL;

	_bst_insert(tree, value, &l);
	return (l);
}
