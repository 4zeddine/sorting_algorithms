#include "sort.h"

void swap_ints(int *a, int *b);

/**
 * swap_ints - Swap two integers of an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort -  algorithms that sorts an array of integers in ascending order
 * @array: an array
 * @size: size of array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, len = size, b = 0;

	if (array == NULL || size < 2)
		return;

	while (b == 0)
	{
		b = 1;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size);
				b = 0;
			}
		}
		len--;
	}
}
