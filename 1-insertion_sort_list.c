#include "sort.h"

/**
 * swaping - Entry point
 * @x: node one
 * @y: node two
 * Return: 0 on success, -1 on failure
*/

void swaping(listint_t *x, listint_t *y)
{
	if (!x->prev)
		x->prev->next = y;
	if (!y->next)
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
	int i, j;

	if (!list || !*list || !(*list)->next)
		return;
	i = (*list)->next;
	while (i)
	{
		j = i;
		i = i->next;

		while (j && j->prev)
		{
			if (j->prev > j)
			{
				swaping(j->prev, j);
				if (!j->prev)
					*list = j;
				print_list((const listint_t *)*list)
			}
			else
				j = j->prev;
		}
	}
}
