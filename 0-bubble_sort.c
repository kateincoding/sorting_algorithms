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
 * bubble_sort - Bubble sort algorithm
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int i = 0, j = 0;

	for (i = 0; i < (size - 1) ; i++)
		for (j = i + 1; j < size; j++)
			if (array[i] > array[j])
				_swap(&array[i], &array[j]);
}
