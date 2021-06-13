#include "sort.h"

/**
 * selection_sort - choose the min number and swap between the initial
 *
 * @array: array of integers
 * @size: size of the array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, index, swap;
	int little;

	if (size <= 1)
		return;

	for (j = 0; j < size; j++)
	{
		/* step1: while through the array to find the small number */
		swap = 0;
		little = array[j];
		for (i = j; i < size; i++)
		{
			if (array[i] < little)
				little = array[i], index = i, swap = 1;
		}
		/* swap */
		if (swap == 1)
		{
			array[index] = array[j];
			array[j] = little;
			print_array(array, size);
		}
	}
}
