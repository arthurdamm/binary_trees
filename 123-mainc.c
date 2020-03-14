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

#define PRINT_INFO 1
#define RAND_ARR 0
#define REMOVE_ALL 0

avl_t *remove_val(avl_t *tree, int val)
{
	
#if PRINT_INFO > 0
	printf("Removing %d...\n", val); 
#endif
	tree = avl_remove(tree, val);

	if (tree && !binary_tree_is_avl(tree))
	{
		/* binary_tree_print(tree); */
		
		printf("---> NOT AVL!!! <---\n");

	}

	
#if PRINT_INFO > 0
	printf("NEW ROOT: %d\n", tree ? tree->n : 0);
	binary_tree_print(tree);
	printf("IS_AVL: %d\n", binary_tree_is_avl(tree));
#endif


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
	size_t i = 0;	
	
#if RAND_ARR == 0
	int array[] = {
		56, 43, 98, 2, 78, 123, 76, 110, 234
	};
	int rarray[] = {
		0
	};
	size_t n = sizeof(array) / sizeof(array[0]);	
	for (i = 0; i < n; i++)
		bst_insert(&tree, array[i]);
#else
	size_t n = 5000;
	int *array = rand_array(n, 100);

	tree = array_to_avl(array, n);
	if (!tree)
		return (1);		
#endif

	
	printf("IS_AVL: %d\n", binary_tree_is_avl(tree));
	printf("==============================\n");

#if REMOVE_ALL == 0
	for (i = 0; i < sizeof(rarray) / sizeof(rarray[0]); i++)
		tree = remove_val(tree, rarray[i]);
#else
	for (i = 0; i < n; i++)
	{
		tree = remove_val(tree, array[i]);
		if (tree && !binary_tree_is_avl(tree))
		{
			/* binary_tree_print(tree); */
			printf("ERROR: %d\n", tree->n);

			exit(1);
		}
	}
#endif

	printf("IS_AVL: %d\n", binary_tree_is_avl(tree));
	binary_tree_delete(tree);

#if RAND_ARR == 1
	free(array);
#endif
	return (0);
}
