#include "sort.h"

/**
 * swap - swaps position values
 * @array: array
 * @i: value to swap
 * @j: value to swap
 * @size: size
 * Return: void
 */
void swap(int *array, int i, int j, size_t size)
{
	int holder = 0;

	holder = array[i];
	array[i] = array[j];
	array[j] = holder;
	print_array(array, size);

}

/**
 * partition_hoare - hoare partition scheme
 * @array: array
 * @low: pointer value to evaluate
 * @high: pointer value to evaluate
 * @size: size
 * Return: void
 */
int partition_hoare(int *array, int low, int high, int size)
{
	int pivot, i, j;

	pivot = array[high];
	i = low - 1;
	j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return  (j);

		swap(array, i, j, size);
	}

}

/**
 * quick_sorter_hoare  - quick sort algorithm recursion
 * @array: array
 * @low: left compare
 * @high: right compare
 * @size: size of the arry
 * @partition_index: partition index
 * Return: Nothing
 */
void quicksorterhoare(int *array, int low, int high, size_t size,
int partition_index)
{
	int partition_index_new, left, right;

	partition_index_new = 0;
	left = 0;
	right = 0;

	if (low < high)
	{
		partition_index_new = partition_hoare(array, low, high, size);
		if (partition_index == partition_index_new)
			partition_index = partition_index_new - 1;
		else
			partition_index = partition_index_new;
		left = partition_index;
		right = partition_index + 1;
		quicksorterhoare(array, low, left, size, partition_index);
		quicksorterhoare(array, right, high, size, partition_index);
	}
}

/**
 * quick_sort_hoare - quick sort algorithm
 * @array: array
 * @size: size of the arry
 * Return: Void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksorterhoare(array, 0, size - 1, size, size);
}
