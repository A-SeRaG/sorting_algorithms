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
	listint_t *i, *j;

	if (!list || !*list || !(*list)->next)
		return;
	i = (*list)->next;
	while (i)
	{
		j = i;
		i = i->next;

		while (j && j->prev)
		{
			if (j->prev->n > j->n)
			{
				swp_node(j->prev, j);
				if (!j->prev)
					*list = j;
				print_list((const listint_t *)*list);
			}
			else
				j = j->prev;
		}
	}
}

