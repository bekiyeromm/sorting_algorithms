#include"sort.h"
void swap(int *a, int *b);
/**
 * selection_sort - sorts an element in acending order
 * @array: array to be sorted
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	if (size < 2)
		return;
	for (i = 0; i < (size - 1); i++)
	{
		min = i;
		for (j = (i + 1); j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			swap(&array[min], &array[i]);
			print_array(array, size);
		}
	}

}
/**
 * swap - swaps the value
 * @a: forst num to be swaped
 * @b: second number to be swaped
 */
void swap(int *a, int *b)
{
	size_t temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
