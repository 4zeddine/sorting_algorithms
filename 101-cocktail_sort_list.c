#include "sort.h"
#include <stdio.h>

listint_t *swap_node(listint_t *node, listint_t **list);

/**
 *swap_node - swap a node for his previous one
 *@node: node
 *@list: node list
 *Return: return a pointer to a node which was enter it
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *sw1 = node->prev, *sw2 = node;

	sw1->next = sw2->next;
	if (sw2->next)
		sw2->next->prev = sw1;
	sw2->next = sw1;
	sw2->prev = sw1->prev;
	sw1->prev = sw2;
	if (sw2->prev)
		sw2->prev->next = sw2;
	else
		*list = sw2;
	return (sw2);
}
/**
 *cocktail_sort_list - this is a cocktail sort implementation
 *working on a double linked lists
 *@list: list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *node;
	int swap_done = 1;

	if (list == '\0' || (*list) == '\0' || (*list)->next == '\0')
		return;
	node = *list;
	while (swap_done == 1)
	{
		swap_done = 0;
		while (node->next)
		{
			if (node->n > node->next->n)
			{
				node = swap_node(node->next, list);
				swap_done = 1;
				print_list(*list);
			}
			node = node->next;
		}
		if (swap_done == 0)
			break;
		swap_done = 0;
		while (node->prev)
		{
			if (node->n < node->prev->n)
			{
				node = swap_node(node, list);
				swap_done = 1;
				print_list(*list);
			}
			else
				node = node->prev;
		}
	}
}
