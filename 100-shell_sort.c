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
 * shell_sort - calculate a gap and take 2 index to compare and swap
 *
 * @array: array of integers
 * @size: size of the array
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 0, i, j;

	if (size <= 1)
		return;

	/* calculate the gap */
	while ((3 * gap + 1) <= size)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
			for (j = i; j >= gap && array[j - gap] > array[j] ; j = j - gap)
				_swap(&array[j], &array[j - gap]);
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
