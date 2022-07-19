#include "sort.h"

void quicksort(int *array, int lo, int high, size_t size);
int partition(int *array, int lo, int high, size_t size);
/**
 * quick_sort - Function to swap to nodes
 * @array: list to be swapped
 * @size: size of array
 *
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
/**
 * partition - Function to swap to nodes
 * @array: list to be swapped
 * @lo: low index
 * @high: low index
 * @size: size of array
 *
 * Return: Nothing
 */
int partition(int *array, int lo, int high, size_t size)
{
	int pivot = 0, i = 0, j = 0, temp = 0;

	pivot = array[high];
	i = lo;
	for (j = lo; j < high; j++)
	{
		if (array[j] < pivot)
		{

			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[high] < array[i])
	{
		temp = array[i];
		array[i] = array[high];
		array[high] = temp;
		if (i != j)
			print_array(array, size);
	}
	return (i);
}
/**
 * quicksort - Function to swap to nodes
 * @array: list to be swapped
 * @lo: low index
 * @high: low index
 * @size: size of array
 *
 * Return: Nothing
 */
void quicksort(int *array, int lo, int high, size_t size)
{
	int p = 0;

	if (lo < high)
	{
		p = partition(array, lo, high, size);
		quicksort(array, lo, p - 1, size);
		quicksort(array, p + 1, high, size);
	}
}
