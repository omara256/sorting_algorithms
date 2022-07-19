#include "sort.h"

/**
 * bubble_sort- Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void bubble_sort(int *array, size_t size)
{
	size_t  i = 0;
	int auxValueArray = 0, j = 1;

	if (array  == NULL)
		return;
	while (j == 1)
	{
		j = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				auxValueArray = array[i + 1];
				array[i + 1] = array[i];
				array[i] = auxValueArray;
				j = 1;
				print_array(array, size);
			}
		}
	}
}
