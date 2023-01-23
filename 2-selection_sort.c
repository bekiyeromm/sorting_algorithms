#include "sort.h"

/**
* selection_sort- Implementing selection sort
* @array: array to be sorted
* @size: size of an array
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;

	if (!array && size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}
		if (min_idx != i)
		{
			swap(&(array[i]), &(array[min_idx]));
			print_array(array, size);
		}
	}
}

/**
* swap- Swapping two integers
* @a: fisrt number to be swapped
* @b: second number to be swapped
*/
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
