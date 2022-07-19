#include "sort.h"
/**
 * counting_sort - Function to swap to nodes
 * @array: list to be swapped
 * @size: size of array
 *
 * Return: Nothing
 */
void counting_sort(int *array, size_t size)
{
	int *output, *count;
	size_t  i;
	int max, j;

	if (size < 2)
		return;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	count = malloc(sizeof(size_t) * (max + 1));
	output = malloc(sizeof(int) * size);

	for (j = 0; j <= max; j++)
		count[j] = 0;

	for (i = 0; i < size; i++)
		count[array[i]] += 1;

	for (j = 1; j <= max; j++)
		count[j] += count[j - 1];

	print_array(count, max + 1);
	for (i = 0; i < size; i++)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}
