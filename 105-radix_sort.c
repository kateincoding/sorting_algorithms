#include "sort.h"

/**
 * recursive_radix_sort - radix sort algorithm - LSD
 * the number of do arecursion is linear depend with
 * the #digits of max number
 * @array: unsorted array of integer
 * @size: size of the array
 * @lsd: least significant digit (1 last: 1, 2nd last: 1*10, 3: 1*10*10)
 *
 * Return: void
 */
void recursive_radix_sort(int *array, size_t size, int lsd)
{
	int index[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int result[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int i, idx_start;

	/* count the repetitions of digits in nbr and store in index */
	for (i = 0; i < (int)size; i++)
		index[(array[i] / lsd) % 10] += 1;

	/* The final of recursion is when the position-digit of all nbr == 0 */
	if (index[0] == (int)size)
		return;
	
	// result = malloc(sizeof(int) * size);
	// if (!result)
	// 	return;
	/* we can work in here building a hash table or hash array */
	/* or work like insertion, let's calculate the index and set */
	for (i = 1; i < 10; i++)
		index[i] += index[i - 1];

	for (i = 9; i > 0; i--)
		index[i] = index[i - 1];
	index[0] = [0];

	/* now let's have a middle sorted array */
	// for (i = (int)size - 1; i >= 0; i--)
	for (i = 0; i < (int)size; i++)
	{
		/* check the start position of array[i] with index table */
		idx_index = (array[i] / lsd) % 10;
		if (idx_index > 0)
			idx_start = index[idx_index - 1];
		else 
			idx_start = index[0];
		/* assign in the partial sorted array */
		result[idx_start] = array[i];
		/* final position decrease 1 because we already assign the value */
		index[idx_index - 1]++;
	}
	
	for (i = 0; i < (int)size; i++)
		array[i] = result[i];
	print_array(array, size);
	/* index -> partial sorted array */
	recursive_radix_sort(array, size, lsd * 10);
}

/**
 * radix_sort - radix sort algorithm - LSD
 * properties:
 * [LSD] least significant digit
 * stable -> not relevant to sort equals values
 * lenght of index table = base of number(binary, 10, hexa)
 * how many times sort -> max number of digit of nbr
 * @array: unsorted array of integer
 * @size: size of the array
 *
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	if (size <= 1)
		return;

	/* one way, we will find how many time sort = #digits of max_number */
	/* Second way, build a recursive fx but it is helpfull if the array is bigger */
	recursive_radix_sort(array, size, 1);
}
