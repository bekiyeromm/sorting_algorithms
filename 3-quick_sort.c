#include "sort.h"

/**
 * swape- to swap two numbers
 * @array: array to be swapped
 * @size: size of array
 * @a: The first number to be swapped
 * @b: The secong number to be swapped
 */
void swape(int array[], int size, int *a, int *b)
{
	if (*a != *b)
	{
		int tmp = *a;
		*a = *b;
		*b = tmp;
		print_array(array, size);
	}
}

/**
 * partitioned- To divide an array and merge
 * @array: an array to be divided and merged
 * @low: 1st index in the array
 * @high: last index in the array
 * @size: size of an array
 * Return: pivot point
 */
int partitioned(int array[], int low, int high, int size)
{
	int i, j, pivot_value = array[high];

	for (i = low, j = low; j < high; j++)
	{
		if (array[j] < pivot_value)
		{
			swape(array, size, &array[j], &array[i++]);
		}
	}
	swape(array, size, &array[i], &array[high]);
	return (i);
}

/**
 * quick_sort_recursion- recursive function to sort an array
 * @arr: an array to be sorted
 * @low: 1st element in the array
 * @high: last element in the array
 * @size: size of an array
 */
void quick_sort_recursion(int *arr, int low, int high, int size)
{
	int pivot_idx;

	if (low < high)
	{
		pivot_idx = partitioned(arr, low, high, size);
		quick_sort_recursion(arr, low, pivot_idx - 1, size);
		quick_sort_recursion(arr, pivot_idx + 1, high, size);
	}
}

/**
 * quick_sort- To sort an array using quick sort
 * @array: array to be sorted
 * @size: size of an array
 */
void quick_sort(int *array, size_t size)
{
	if (array && size >= 2)
		quick_sort_recursion(array, 0, size - 1, size);
}
