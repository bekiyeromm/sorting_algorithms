#include "sort.h"
/**
 * partition - quicksort using Hoare version
 * @array: array to sort
 * @min: lowest index
 * @max: highest index
 * @size: size of the array
 * Return: partition index
 */
size_t partition(int *array, ssize_t min, ssize_t max, size_t size)
{
	int swap, pivot;

	pivot = array[max];
	while (min <= max)
	{
		while (array[min] < pivot)
			min++;
		while (array[max] > pivot)
			max--;
		if (min <= max)
		{
			if (min != max)
			{
				swap = array[min];
				array[min] = array[max];
				array[max] = swap;
				print_array(array, size);
			}
			min++;
			max--;
		}
	}
	return (max);
}

/**
 * quicksort - sorts a partition of an array of integers
 * @array: array to sort
 * @min: lowest index of the partition to sort
 * @max: highest index of the partition to sort
 * @size: size of the array
 * Return: void
 */
void quicksort(int *array, ssize_t min, ssize_t max, size_t size)
{
	ssize_t pivot;

	if (min < max)
	{
		pivot = partition(array, min, max, size);
		quicksort(array, min, pivot, size);
		quicksort(array, pivot + 1, max, size);

	}
}

/**
 * quick_sort_hoare - sorts an array of integer with quick sort
 * @array: The array to sort
 * @size: The size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
