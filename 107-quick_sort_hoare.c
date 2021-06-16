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
 * hoare_partition - Hoare partition the array
 * the pivot is part of while
 *
 * @array: array
 * @left: first int pointer
 * @right: second int pointer
 * @size: size of the array
 * Return: void
 */
int hoare_partition(int *array, int left, int right, size_t size)
{
	int i, j, pivot;

	pivot = array[right]; /* pivot start at left */
	i = left; /* in the for i = left + 1 */
	/* pivot is part of the while */
	for (i = left, j = right; "C is fun"; i++, j--)
	{
		while (array[i] < pivot)
			i++;
		while (array[j] > pivot)
			j--;
		/* while stop when j < i */
		/* don't need to swap the pivot because it is already part of while */
		if (j <= i)
			return (i);
		/* p | <p [big] --need to continue to run -- [ small] >p */
		_swap(&array[i], &array[j]);
		print_array(array, size);
	}
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
	p = hoare_partition(array, left, right, size);
	recursive_quick_sort(array, left, p - 1, size);
	recursive_quick_sort(array, p, right, size);
}

/**
 * quick_sort_hoare - choose a pivot and be part of while
 * for this case pivot = last element
 * best case - pivot is the middle value of array (O(nlog(n))
 * worst case - sorted -> necesary we will need to run O(n^2)
 *
 * @array: array of integers
 * @size: size of the array
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (size <= 1)
		return;
	recursive_quick_sort(array, 0, size - 1, size);
}
