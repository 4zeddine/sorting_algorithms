#include "sort.h"

/**
 * swap_node - Swap two nodes in a listint_t doubly-linked list.
 * @h: A pointer to the head of the doubly-linked list.
 * @sn1: A pointer to the first node to swap.
 * @sn2: A pointer to the second node to swap.
 */
void swap_node(listint_t **h, listint_t **sn1, listint_t *sn2)
{
	(*sn1)->next = sn2->next;
	if (sn2->next != NULL)
		sn2->next->prev = *sn1;
	sn2->prev = (*sn1)->prev;
	sn2->next = *sn1;
	if ((*sn1)->prev != NULL)
		(*sn1)->prev->next = sn2;
	else
		*h = sn2;
	(*sn1)->prev = sn2;
	*sn1 = sn2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Return: A void.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			swap_node(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
