#ifndef SORT_H
#define SORT_H

#include<stdio.h>
#include <stdlib.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
/*swap function for buble sort*/
void swap(int *a, int *b);

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
listint_t *swap_node(listint_t *node, listint_t **list);
/*quick sort*/
void quick_sort(int *array, size_t size);
void swape(int array[], int size, int *a, int *b);
int partitioned(int array[], int low, int high, int size);
void quick_sort_recursion(int *arr, int low, int high, int size);

/*shel sort*/
void shell_sort(int *array, size_t size);
/*cocktail shake*/
void cocktail_sort_list(listint_t **list);
void move_left(listint_t *curr, listint_t *prev, listint_t **head);

/*counting sort*/
void counting_sort(int *array, size_t size);
/*merge sort*/
void merge_sort(int *array, size_t size);

/*heap sort*/
void heap_sort(int *array, size_t size);
void make_heap(int *array, size_t size);
void sift_down(int *array, size_t root, size_t end, size_t size);

/*radix sort*/
void radix_sort(int *array, size_t size);
/*bitonic sort*/
void bitonic_sort(int *array, size_t size);
/*quick sort hoare partition schem sort*/
void quick_sort_hoare(int *array, size_t size);

#endif
