#include "sort.h"

/**
 * merge - merge left side with right side
 * @array: unsorted array of integer and result
 * @helper: copy of the part we want to sort of array
 * @low: low limit of the unsorted block of array
 * @middle: separation between 2 block, it is in left side
 * @high: high limit of the unsorted block of array
 *
 * Return: void
 */
void merge(int *array, int *helper, int low, int middle, int high)
{
	int helperLeft = low, helperRight = middle + 1, current = low;
	int i, current_print;

	/* create a strdup of the array in helper */
	for (i = low; i <= high; i++)
		helper[i] = array[i];

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + helperLeft, helperRight - helperLeft);
	printf("[right]: ");
	print_array(array + helperRight, high + 1 - helperRight);
	/* Iterate through helper array */
	/* compare between left part and right part */
	/* copy the sorted order in the array */
	current_print = current;
	while (helperLeft <= middle || helperRight <= high)
	{
		if (helperLeft <= middle && helperRight <= high)
		{
			if (helper[helperLeft] <= helper[helperRight])
				array[current] = helper[helperLeft], current++, helperLeft++;
			else
				array[current] = helper[helperRight], current++, helperRight++;
		}
		else if (helperLeft >= middle && helperRight <= high)
			array[current] = helper[helperRight], current++, helperRight++;
		else
			array[current] = helper[helperLeft], current++, helperLeft++;
	}
	printf("[Done]: ");
	print_array(array + current_print, high + 1 - low);
}

/**
 * recursive_merge_sort - recursive merge sort algorithm, divide in 2 part
 * where left < right
 * @array: unsorted array of integer
 * @helper: helper array from array
 * @low: helper Left
 * @high: helper righ
 *
 * Return: void
 */
void recursive_merge_sort(int *array, int *helper, int low, int high)
{
	int middle;

	if (low < high && array)
	{
		middle = (low + high - 1) / 2;
		recursive_merge_sort(array, helper, low, middle); /* sort left */
		recursive_merge_sort(array, helper, middle + 1, high); /* sort right */
		merge(array, helper, low, middle, high); /* merge them */
	}
}

/**
 * merge_sort - merge sort algorithm
 * @array: unsorted array of integer
 * @size: size of the array
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *helper;

	if (!array || size < 2)
		return;
	helper = malloc(sizeof(int) * size);
	if (!helper)
		return;

	recursive_merge_sort(array, helper, 0, size - 1);
	free(helper);
}
