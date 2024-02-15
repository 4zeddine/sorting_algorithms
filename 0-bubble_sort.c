#include "sort.h"

/**
 * bubble_sort -  algorithms that sorts an array of integers in ascending order
 * @array: an array
 * @size: size of array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j, tmp = 0;

	if (!array || size < 2)
		return;
	for (i = 0; i < size; i++)
		for (j = 0; j < size; j++)
		{
			if (array[j] > array[j + 1] && array[j + 1])
			{
			tmp = array[j];
			array[j] = array[j + 1];
			array[j + 1] = tmp;
			print_array(array, size);
			}
		}
}