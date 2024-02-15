#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending
 * order using the Selection sort algorithm
 * @size: size of the array
 * @array: input array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, index;
	int tmp, k, l = 0;

	if (array == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		tmp = i;
		l = 0;
		for (index = i + 1; index < size; index++)
		{
			if (array[tmp] > array[index])
			{
				tmp = index;
				l += 1;
			}
		}
		k = array[i];
		array[i] = array[tmp];
		array[tmp] = k;
		if (l != 0)
			print_array(array, size);
	}
}

