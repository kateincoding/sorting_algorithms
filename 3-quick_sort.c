#include "sort.h"

/**
 * _swap - swap between 2 pointers of int
 *
 * @a: first int pointer
 * @b: second int pointer
 * Return: void
 */
void _swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * partition - partition the array
 *
 * @array: array
 * @left: first int pointer
 * @right: second int pointer
 * @size: size of the array
 * Return: void
 */
int partition(int *array, int left, int right, size_t size)
{
	int i, j, pivot;

	pivot = array[right];
	i = left - 1;
	for (j = left; j <= right - 1; j++)
	{
		if (array[j] < pivot)
		{
			i = i + 1;
			if (array[i] != array[j])
			{
				_swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[right])
	{
		_swap(&array[i + 1], &array[right]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * recursive_quick_sort - recursive to the array to have quick sort
 *
 * @array: array
 * @left: first int pointer
 * @right: second int pointer
 * @size: size of the array
 * Return: void
 */
void recursive_quick_sort(int *array, int left, int right, size_t size)
{
	int p;

	if (left >= right)
		return;
	p = partition(array, left, right, size);
	recursive_quick_sort(array, left, p - 1, size);
	recursive_quick_sort(array, p + 1, right, size);
}

/**
 * quick_sort - choose the min number and swap between the initial
 *
 * @array: array of integers
 * @size: size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (size <= 1)
		return;
	recursive_quick_sort(array, 0, size - 1, size);
}
