#include "sort.h"
#include <stdio.h>

void swap_ints(int *a, int *b);
void merge(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);

/**
 * swap_ints - swaps two ints in an array.
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
 * merge - sorts an array with the bitonic sequence.
 * @array: input array.
 * @size: The size of the array.
 * @first: The first element of the array to sort.
 * @seq: The size of the sequence to sort.
 * @flow: The order to sort in.
 */
void merge(int *array, size_t size, size_t first, size_t seq,
		char flow)
{
	size_t i, jump = seq / 2;

	if (seq > 1)
	{
		for (i = first; i < first + jump; i++)
		{
			if ((flow == 0 && array[i] > array[i + jump]) ||
			    (flow == 1 && array[i] < array[i + jump]))
				swap_ints(array + i, array + i + jump);
		}
		merge(array, size, first, jump, flow);
		merge(array, size, first + jump, jump, flow);
	}
}

/**
 * bitonic_seq - uses the bitonic algorithm.
 * @array: input array.
 * @size: The size of the array.
 * @first: The first element of the array to sort.
 * @seq: The size of a bitonic sequence.
 * @flow: The order to sort in.
 */
void bitonic_seq(int *array, size_t size, size_t first, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == 0) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + first, seq);

		bitonic_seq(array, size, first, cut, 0);
		bitonic_seq(array, size, first + cut, cut, 1);
		merge(array, size, first, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + first, seq);
	}
}

/**
 * bitonic_sort - usues the bitonic algorithm to
 * sort an array of integers in ascending order.
 * @array: input array.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, 0);
}
