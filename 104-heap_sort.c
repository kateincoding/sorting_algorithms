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
 * heapify - build a heap tree where the head is bigger of value branches
 * @array: unsorted array of integer
 * @size: size of the array
 * @i: index of starter head
 * @print_size: size of the array to print
 *
 * Return: void
 */
void heapify(int *array, size_t size, int i, size_t print_size)
{
	int head = i; /* head to compare -> big number */
	int left = 2 * i + 1; /* left branch */
	int right = 2 * i + 2; /* right branch */

	/* left exist && left branch > head */
	if (left < (int)size && array[left] > array[head])
		head = left;
	/* right exist && right branch > head */
	if (right < (int)size && array[right] > array[head])
		head = right;
	/* if the head needs to change */
	if (head != i)
	{
		/* if the value is the same, don't swap */
		_swap(&array[i], &array[head]);
		print_array(array, print_size);
		/* we need to heapify all the tree again */
		heapify(array, size, head, print_size);
	}
}

/**
 * heap_sort - heap sort algorithm
 * @array: unsorted array of integer
 * @size: size of the array
 *
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	int first_head, i;
	size_t print_size = size;

	if (size <= 1 || !array)
		return;

	/* calculate the index of the first_head */
	first_head = (int)(size / 2 - 1);
	/* heapify the array */
	for (i = first_head; i >= 0; i--)
		heapify(array, size, i, print_size);

	/* extract each element from heap */
	for (i = size - 1; i >= 0; i--)
	{
		/* if the index is different from 0 */
		/* if it is equals value, we need to change */
		if (i != 0)
		{
			_swap(&array[0], &array[i]);
			print_array(array, print_size);
			heapify(array, i, 0, print_size); /* we need to heapify again in 0 */
		}
	}
}
