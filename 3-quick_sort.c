#include "sort.h"
/**
 * partition - sort an array of integers using quick_sort
 * lomuto implementation with pivot in last element of partition
 * @array: array to sort
 * @min: minimum value
 * @max: max value
 * @size: the size of the array to sort
 * Return: index + 1
 */
size_t partition(int *array, ssize_t min, ssize_t max, size_t size)
{
	ssize_t i, j;
	int swap, pivot;

	pivot = array[max];
	i = min - 1;
	for (j = min; j < max; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap = array[i];
				array[i] = array[j];
				array[j] = swap;
				print_array(array, size);
			}
		}
	}
	if (array[max] < array[i + 1])
	{
		swap = array[i + 1];
		array[i + 1] = array[max];
		array[max] = swap;
		print_array(array, size);
	}
	return (i + 1);
}

/**
* quicksort - sorts an array (a partition recursively)
* @array: array to be sorted
* @min: min index of the partition
* @max: max index of the partition
* @size: array size
*/
void quicksort(int *array, ssize_t min, ssize_t max, size_t size)
{
	ssize_t pivot;

	if (min < max)
	{
		pivot = partition(array, min, max, size);
		quicksort(array, min, pivot - 1, size);
		quicksort(array, pivot + 1, max, size);

	}
}

/**
* quick_sort - sorts an array with quick sort algo
* @array: The array to be sorted
* @size: The size of the array to be sorted
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
