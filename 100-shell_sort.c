#include "sort.h"
/**
 * shell_sort - Function to swap to nodes
 * @array: list to be swapped
 * @size: size of array
 *
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
	int tmp;
	size_t  i = 0, j = 0, d = 1;

	if (array == NULL || size < 2)
		return;
	while (d <= size / 3)
	{
		d = (d * 3) + 1;
	}
	while (d > 0)
	{
		for (i = d; i < size; i++)
		{
			tmp = array[i];
			j = i;
			while (j > d - 1 && array[j - d] >= tmp)
			{
				array[j] = array[j - d];
				j = j - d;
			}
			array[j] = tmp;
		}
		print_array(array, size);
		d = (d - 1) / 3;
	}
}
