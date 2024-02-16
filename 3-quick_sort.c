#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void ls(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - swaps two integers.
 * @a: The first int to swap.
 * @b: The second int to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - the lomuto partition scheme implementation.
 * @array: The input array.
 * @size: The size of the array.
 * @first: The starting element of the array.
 * @last: The ending element of the array.
 *
 * Return: The index of the last element sorted.
 */
int lomuto_partition(int *array, size_t size, int first, int last)
{
	int *pivot, above, below;

	pivot = array + last;
	for (above = below = first; below < last; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * ls - implements the quicksort algorithm.
 * @array: the input array.
 * @size: The size of the array.
 * @first: The starting element of the array.
 * @last: The ending element of the array.
 */
void ls(int *array, size_t size, int first, int last)
{
	int part;

	if (last - first > 0)
	{
		part = lomuto_partition(array, size, first, last);
		ls(array, size, first, part - 1);
		ls(array, size, part + 1, last);
	}
}

/**
 * quick_sort - uses the quick sort algo to sort an array.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	ls(array, size, 0, size - 1);
}
