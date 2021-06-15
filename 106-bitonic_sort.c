#include "sort.h"

/**
 * bitonic_print - function to print part of step in bitonic
 * @dir: 1 if it increas, otherwise, 0 decrease
 * @step: 0 if is "Merging" and 1 if is "Result"
 * @array: array to be sorted
 * @start: start index of the partly array
 * @final: final index of the partly array
 * @size: size of the array
 * @print_size: print size
 *
 * Return: Always 0
 */
void bitonic_print(int dir, int step, int *array, int start,
				int final, size_t size, size_t print_size)
{
	int i;

	if (dir == 1 && step == 0)
		printf("Merging [%d/%d] (UP):\n", (int)size, (int)print_size);
	else if (dir == 0 && step == 0)
		printf("Merging [%d/%d] (DOWN):\n", (int)size, (int)print_size);
	else if (dir == 1 && step == 1)
		printf("Result [%d/%d] (UP):\n", (int)size, (int)print_size);
	else if (dir == 0 && step == 1)
		printf("Result [%d/%d] (DOWN):\n", (int)size, (int)print_size);

	for (i = start; i <= final; i++)
	{
		if (i > start)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}


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
 * bitonic_merge - merge both part of the array
 * @direction: 1 if it increas, otherwise, 0 decrease
 * @array: array to be sorted
 * @start_idx: start index of the partly array
 * @size: size of the array
 * @print_size: print size
 *
 * Return: Always 0
 */
void bitonic_merge(int direction, int *array,
				int start_idx, size_t size, size_t print_size)
{
	int i = start_idx, middle;

	if (size > 1)
	{
		middle = size / 2;

		for (i = start_idx; i < start_idx + middle; i++)
			if (middle != 0 && direction == (array[i] > array[i + middle]))
				_swap(&array[i], &array[i + middle]);
		bitonic_merge(direction, array, start_idx, middle, print_size);
		bitonic_merge(direction, array, start_idx + middle, middle, print_size);
	}
}

/**
 * recursive_bitonic_sort - bitonic sort algorithm
 * @direction: 1 if it increas, otherwise, 0 decrease
 * @array: array to be sorted
 * @start_idx: start index of the partly array
 * @size: size of the array
 * @print_size: print size
 *
 * Return: Always 0
 */
void recursive_bitonic_sort(int direction, int *array,
				int start_idx, size_t size, size_t print_size)
{
	int middle = size;

	if (size <= 1)
		return;

	bitonic_print(direction, 0, array, start_idx, start_idx + middle - 1,
					size, print_size);
	middle = size / 2;
	/* recursion for the left and right side */
	recursive_bitonic_sort(1, array, start_idx, middle, print_size);
	recursive_bitonic_sort(0, array, start_idx + middle, middle, print_size);
	/* merge 2 arrays */
	bitonic_merge(direction, array, start_idx, size, size);
	bitonic_print(direction, 1, array, start_idx,
					start_idx + 2 * middle - 1, size, print_size);
}

/**
 * bitonic_sort - bitonic sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: Always 0
 */
void bitonic_sort(int *array, size_t size)
{
	if (size <= 1 || !array)
		return;

	recursive_bitonic_sort(1, array, 0, size, size);
}
