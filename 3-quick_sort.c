#include "sort.h"

/**
 * quick_sort - sort array using quick sort method
 * @array: the array
 * @size: the size
 */
void quick_sort(int *array, size_t size)
{
	sort(array, 0, size - 1, size);
}

/**
 * sort - recursive sort function
 * @array: the array
 * @size: the size
 * @low: the low limit
 * @high: the hish limit
 */
void sort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		sort(array, low, pivot - 1, size);
		sort(array, pivot + 1, high, size);
	}
}

/**
 * partition - partition and order the array
 * @array: the array
 * @size: the size
 * @low: the low limit
 * @high: the hish limit
 * Return: return the position of i (the new pivot)
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j, temp;

	pivot = array[high];

	i = low - 1;
	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	i++;
	if (i != j)
	{
		temp = array[i];
		array[i] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i);
}
