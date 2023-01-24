#include "sort.h"
/**
 * merge - merges left_index and right_index arrays
 * into original array
 *
 * @array: pointer to array
 * @size: size of the array
 * @l: pointer to left array
 * @r: pointer to right array
 **/
void merge(int *array, int *left, int *right, size_t size)
{
	int i = 0, j = 0, k = 0;
	int size_l, size_r;

	size_l = size / 2;
	size_r = size - size_l;

	printf("Merging...\n");

	printf("[left]: ");
	print_array(left, size_l);

	printf("[right]: ");
	print_array(right, size_r);

	while (i < size_l && j < size_r)
	{
		if (left[i] < right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}

	while (i < size_l)
		array[k++] = left[i++];

	while (j < size_r)
		array[k++] = right[j++];
	printf("[Done]: ");
	print_array(array, size);
}
/**
 * merge_sort - sorts an array of integers in ascending order using
 * the Merge sort algorithm
 * @array: pointer to array
 * @size: size of the array
 **/
void merge_sort(int *array, size_t size)
{
	size_t mid = 0, i;
	int left[100];
	int right[100];

	if (!array)
		return;

	if (size < 2)
		return;

	mid = (size / 2);

	for (i = 0; i < mid; i++)
		left[i] = array[i];

	for (i = mid; i < size; i++)
		right[i - mid] = array[i];

	merge_sort(left, mid);
	merge_sort(right, size - mid);
	merge(array, left, right, size);
}
