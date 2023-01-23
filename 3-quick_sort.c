#include "sort.h"

/**
 * do_partition - Function that divide the list
 *
 * @array: Array of number to sort.
 * @low: data in the index 0 of the list.
 * @high: data in the (last index - 1) of the list.
 * @size: Size of the array.
 * Return: the partition index.
 */

int do_partition(int *array, int low, int high, size_t size)
{
	int pivot;
	int i, j, temp1, temp2;

	pivot = array[high];
	i = (low - 1);

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp1 = array[i];
			array[i] = array[j];
			array[j] = temp1;
			if (i != j)
				print_array(array, size);
		}
	}
	if (pivot < array[i + 1])
	{
		temp2 = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp2;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * q_sorting - Function that sort the list
 *
 * @array: Array of number to sort.
 * @low: data in the index 0 of the list.
 * @high: data in the last - 1 index of the list.
 * @size: Size of the array.
 * Return: Void
 */

void q_sorting(int *array, int low, int high, size_t size)
{
	int partition_number;

	if (low < high)
	{
		partition_number = do_partition(array, low, high, size);
		q_sorting(array, low, partition_number - 1, size);
		q_sorting(array, partition_number + 1, high, size);
	}
}

/**
 * quick_sort -  divide-and-conquer sorting algorithm
 *
 * @array: Array of number to sort.
 * @size: Size of the array.
 * Return: Void
 */

void quick_sort(int *array, size_t size)
{
	int low = 0;
	int high = size - 1;

	if (size < 2)
	{
		return;
	}
	q_sorting(array, low, high, size);
}
