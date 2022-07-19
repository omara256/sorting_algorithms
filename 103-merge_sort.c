#include "sort.h"

void TopDownMergeSort(int *array, int *copy, size_t size);
void TopDownSplitMerge(int *copy, int iBegin, int iEnd, int *array);
void TopDownMerge(int *array, int iBegin, int iMiddle, int iEnd, int *copy);
void CopyArray(int *array, int iBegin, int iEnd, int *copy);

/**
 * merge_sort - Function to swap to nodes
 * @array: list to be swapped
 * @size: size of array
 *
 * Return: Nothing
 */
void merge_sort(int *array, size_t size)
{
	int *copy;

	if (!array || size < 2)
		return;

	copy = malloc(sizeof(int) * size);
	TopDownMergeSort(array, copy, size);
	free(copy);
}
/**
 * TopDownMergeSort - Function to swap to nodes
 * @array: list to be swapped
 * @copy: copy of array
 * @size: size of array
 *
 * Return: Nothing
 */
void TopDownMergeSort(int *array, int *copy, size_t size)
{
	CopyArray(array, 0, size, copy);
	TopDownSplitMerge(copy, 0, size, array);
}
/**
 * TopDownSplitMerge - Function to swap to nodes
 * @copy: copy to be swapped
 * @iBegin: copy of array
 * @iEnd: size of array
 * @array: array to be swapped
 *
 * Return: Nothing
 */
void TopDownSplitMerge(int *copy, int iBegin, int iEnd, int *array)
{
	int iMiddle;

	if (iEnd - iBegin < 2)
		return;
	iMiddle = (iEnd + iBegin) / 2;

	TopDownSplitMerge(array, iBegin,  iMiddle, copy);
	TopDownSplitMerge(array, iMiddle,    iEnd, copy);
	TopDownMerge(copy, iBegin, iMiddle, iEnd, array);
}
/**
 * TopDownMerge - Function to swap to nodes
 * @array: copy to be swapped
 * @iBegin: copy of array
 * @iMiddle: size of array
 * @iEnd: array to be swapped
 * @copy: array to be swapped
 *
 * Return: Nothing
 */
void TopDownMerge(int *array, int iBegin, int iMiddle, int iEnd, int *copy)
{
	int i, j, k;

	i = iBegin, j = iMiddle;
	if (array)
	{
		printf("Merging...\n");
		printf("[left]: ");
		print_array(array + iBegin, iMiddle - iBegin);
		printf("[right]: ");
		print_array(array + iMiddle, iEnd - iMiddle);
	}
	for (k = iBegin; k < iEnd; k++)
	{

		if (i < iMiddle && (j >= iEnd || array[i] <= array[j]))
		{
			copy[k] = array[i];
			i = i + 1;
		}
		else
		{
			copy[k] = array[j];
			j = j + 1;
		}
	}
	printf("[Done]: ");
	print_array(copy + iBegin, iEnd - iBegin);
}

/**
 * CopyArray - Function to swap to nodes
 * @array: copy to be swapped
 * @iBegin: copy of array
 * @iEnd: array to be swapped
 * @copy: array to be swapped
 *
 * Return: Nothing
 */
void CopyArray(int *array, int iBegin, int iEnd, int *copy)
{
	int k;

	for (k = iBegin; k < iEnd; k++)
		copy[k] = array[k];
}
