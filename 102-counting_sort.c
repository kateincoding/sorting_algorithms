#include "sort.h"

/**
 * max_value - max value of an array of integers
 *
 * @array: array of integers
 * @size: size of the array
 * Return: max number of the array
 */
int max_value(int *array, size_t size)
{
	size_t i = 0;
	int max_number = 0;

	while (i < size)
	{
		if (max_number < array[i])
			max_number = array[i];
		i++;
	}
	return (max_number);
}

/**
 * counting_sort - counting sort algorithm
 *
 * @array: array of integers
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count_array, *new_array;
	int max = 0, i = 0;

	if (size <= 1)
		return;
	/* First, find the biggest value */
	max = max_value(array, size);
	/* Second, make an array of counter to each value */
	count_array = malloc(sizeof(int) * (max + 1));
	if (!count_array)
		return;
	for (i = 0; i <= max; i++)
		count_array[i] = 0;
	/* Third, assign the values = counter of numbers O(n)*/
	for (i = 0; i < (int)size; i++)
		count_array[(array[i])] += 1;
	/* Four, reset: array of acumulative sum O(k)*/
	for (i = 0; i < max; i++)
		count_array[i + 1] += count_array[i];
	print_array(count_array, max + 1);
	/* 5, array of index it is same of 4th but value - 1*/
	/* set the result array */
	new_array = malloc(sizeof(int) * size);
	if (!new_array)
	{
		free(count_array);
		return;
	}
	/* input array -> 1 0 3 1 3 1 */
	/* index               -> 0 1 2 3 */
	/* value(position - 1) -> 1 4 4 x */
	for (i = 0; i < (int)size; i++)
	{
		new_array[count_array[array[i] - 1]] = array[i];
		count_array[(array[i] - 1)] += 1;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = new_array[i];
	free(count_array);
	free(new_array);
}
