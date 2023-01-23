#include "sort.h"
void swap(int *a, int *b);
/**
 * bubble_sort - sort an array of integer in ascending order
 * @array: the array to order and print
 * @size: size of array to order
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int i = 0, j = 0;

	if (size < 1 || array == NULL)
		return;

	for (i = 0; i < (size - 1); i++)
		for (j = 0; j < (size - i - 1); j++)
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
}
/**
 * swap - swaps the value of two variable
 * @a: first number to be swaped
 * @b: second number to be swaped
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
