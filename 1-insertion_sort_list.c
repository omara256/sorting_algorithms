#include "sort.h"
/**
 * swapNode - Function to swap to nodes
 * @copy: list to be swapped
 *
 * Return: Nothing
 */
void swapNode(listint_t *copy)
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
	if (copy->prev != NULL)
		copy = copy->prev;
}

/**
 * insertion_sort_list - insertion sort algorythm
 * @list: list to be insertion_sort
 *
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *ant, *act, *sgt, *aux;
	int i = 0;

	if (list == NULL || *list == NULL)
		return;
	if ((*list)->next == NULL)
		return;
	ant = *list, act = *list, sgt = *list;
	if (sgt->next != NULL)
		sgt = sgt->next;
	else
		return;
	while (act->next)
	{
		if (act->n > sgt->n)
		{swapNode(act);
			if (i == 0)
				(*list) = (*list)->prev;
			print_list(*list);
			ant = act->prev;
			if (act->next != NULL)
				sgt = act->next;
			while (ant->prev)
			{	aux = ant, ant = ant->prev;
				if (aux->n < ant->n)
				{	swapNode(ant);
					if ((*list)->prev != NULL)
						(*list) = ant->prev;
					print_list(*list), ant = ant->prev;
				}	else
					break;
			}
		}	else
		{
			if (act->next != NULL)
				act = act->next;
			if (sgt->next != NULL)
				sgt = sgt->next;
		}	i++;
	}
}
