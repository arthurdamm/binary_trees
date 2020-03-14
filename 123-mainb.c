#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"
#include <time.h>

/**
 * rand_array - generates random int array
 *
 * @len: the length of the array
 * @max: the max size of each integer
 * 
 * Return: the generated int array
 */
int *rand_array(int len, int max)
{
	int *arr;

	arr = calloc(len, sizeof(int));
	if (!arr)
		return (NULL);
	if (!max)
		max = RAND_MAX;
	srand(time(NULL));
	while (len--)
		arr[len] = rand() % max;
	return (arr);
}


avl_t *remove_val(avl_t *tree, int val)
{
	/*
	printf("Removing %d...\n", val); 
	printf("NEW ROOT: %d\n", tree ? tree->n : 0);
	binary_tree_print(tree);
	*/

	tree = avl_remove(tree, val);
	
	return tree;
}

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
	avl_t *tree = NULL;
	

	
	int array[] = {
		4, 1, 7, 0, 3, 2, 6, 8, 5, 9
	};
	size_t n = sizeof(array) / sizeof(array[0]);	
	size_t i = 0;

	/*
	size_t n = 1000;
	int *array = rand_array(n, 10);
	*/

	for(i = 0; i < n; i++)
		bst_insert(&tree, array[i]);

	/* tree = array_to_avl(array, n); */
	if (!tree)
		return (1);
	binary_tree_print(tree);
	printf("IS_AVL: %d\n", binary_tree_is_avl(tree));
	printf("==============================\n");
	tree = remove_val(tree, 7);
	binary_tree_print(tree);
	printf("IS_AVL: %d\n", binary_tree_is_avl(tree));
	tree = remove_val(tree, 8);
	binary_tree_print(tree);
	printf("IS_AVL: %d\n", binary_tree_is_avl(tree));
/*
	for (i = 0; i < (ssize_t)n; i++)
	{
		tree = remove_val(tree, array[i]);
		if (tree && !binary_tree_is_avl(tree))
		{
			binary_tree_print(tree);
			printf("ERROR: %d\n", tree->n);

			exit(1);
		}
	}
*/

	printf("IS_AVL: %d\n", binary_tree_is_avl(tree));
	binary_tree_delete(tree);
	/* free(array); */
	return (0);
}
