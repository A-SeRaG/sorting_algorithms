#include "sort.h"

/**
 * swp_node - swap 2 nodes in list
 * @x: node one
 * @y: node two
 * Return: void
*/

void swp_node(listint_t *x, listint_t *y)
{
	if (x->prev)
		x->prev->next = y;
	if (y->next)
		y->next->prev = x;
	x->prev = y;
	y->next = x;
	x->next = y->next;
	x->prev = y->prev;
}

/**
 * insertion_sort_list - Entry point
 * @list: douple pointer
 * Return: always succuss
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *j, *k;

	if (!list || !*list || !(*list)->next)
		return;

	for (i = (*list)->next; i != NULL; i = i->next)
	{
		k = i->next;
		j = i->prev;
		while (j != NULL && i->n < j->n)
		{
			swp_node(list, j, i);
			print_list((const listint_t *)*list);
		}
	}
}

