#include "sort.h"
/**
 * get_Max - Function to swap to nodes
 * @array: list to be swapped
 * @size: size of array(digits)
 *
 * Return: Nothing
 */
int get_Max(int *array, size_t size)
{
	int max;
	size_t i;

	max = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * countingSort - Function to swap to nodes
 * @array: list to be swapped
 * @size: size of array(digits)
 * @place: places of array element(digits)
 *
 * Return: Nothing
 */
void countingSort(int *array, size_t size, int place)
{
	int *output, count[10] = {0};
	size_t i;
	int max;

	if (array == NULL || size < 2)
		return;

	max = (array[0] / place) % 10;
	for (i = 1; i < size; i++)
	{
		if (((array[i] / place) % 10) > max)
			max = array[i];
	}

	output = malloc(sizeof(int) * size);
	if (output == NULL)
	{
		return;
	}

	for (i = 0; i < size; i++)
		count[(array[i] / place) % 10] += 1;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		output[count[(array[i] / place) % 10] - 1] = array[i];
		count[(array[i] / place) % 10] -= 1;
	}
	print_array(output, size);
	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}

/**
 * radix_sort - Function to swap to nodes
 * @array: list to be swapped
 * @size: size of array
 *
 * Return: Nothing
 */
void radix_sort(int *array, size_t size)
{
	int max, place;

	if (array == NULL || size < 2)
		return;
	max = get_Max(array, size);
	for (place = 1; max / place > 0; place *= 10)
	{
		countingSort(array, size, place);
	}
}
