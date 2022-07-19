#include "sort.h"

/**
 * selection_sort- Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void selection_sort(int *array, size_t size)
{
	size_t  i = 0, j = 0, k = 0;
	int auxValueArray = 0;

	if (array  == NULL)
		return;
	while (i < size - 1)
	{
		j = size - 1;
		k = i + 1;
		while (j > i)
		{
			if (array[j] < array[k])
			{
				k = j;
			}
			j--;
		}
		if (array[i] > array[k])
		{
			auxValueArray = array[i];
			array[i] = array[k];
			array[k] = auxValueArray;
			print_array(array, size);
		}
		i++;
	}
}
