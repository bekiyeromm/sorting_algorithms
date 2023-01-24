#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using the
 * Shell sort
 * @array: array to be sorted
 * @size: number of elements of the array to be sorted
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, gap = 1;
	int val;

	if (array == NULL || size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			val = array[i];
			for (j = i; j >= gap && array[j - gap] > val; j = j - gap)
				array[j] = array[j - gap];
			array[j] = val;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
