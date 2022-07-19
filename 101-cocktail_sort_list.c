#include "sort.h"
/**
 * swapNode101 - Function to swap to nodes
 * @copy: list to be swapped
 *
 * Return: Nothing
 */
void swapNode101(listint_t *copy)
{
	listint_t *nextAux;
	listint_t *copyHead = copy;

	if (copyHead->next == NULL)
		return;
	copyHead = copyHead->next;
	nextAux = copyHead->next;
	if (copyHead->next != NULL)
		copyHead->next->prev = copy;
	if (copy->prev != NULL)
		copy->prev->next = copyHead;
	copyHead->next = copy;
	copyHead->prev = copy->prev;
	copy->next = nextAux;
	copy->prev = copyHead;
}
/**
* cocktail_sort_list - Function to swap to nodes
* @list: list to be swapped
*
* Return: Nothing
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *actList, *prevList;
	int exit = 1;

	if (list == NULL || *list == NULL)
		return;
	if ((*list)->next == NULL)
		return;
	actList = (*list), prevList = (*list);
	while (exit == 1)
	{
		exit = 0;
		while (actList->next)
		{
			if (actList->n > actList->next->n)
			{
				swapNode101(actList);
				if ((*list)->prev != NULL)
					(*list) = (*list)->prev;
				print_list(*list);
				exit = 1;
			} else
				actList = actList->next;
		}
		prevList = actList;
		while (prevList->prev)
		{
			if (prevList->prev == NULL)
				return;
			if (prevList->n < prevList->prev->n)
			{
				swapNode101(prevList->prev);
				if ((*list)->prev != NULL)
					(*list) = (*list)->prev;
				print_list(*list), exit = 1;
			} else
				prevList = prevList->prev;
		}
		actList = prevList;
	}
}
