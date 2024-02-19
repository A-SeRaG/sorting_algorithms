#include "sort.h"

/**
 * swp_node - Swap two nedes
 * @h: A pointer to the head of the list.
 * @n1: A pointer to the first node
 * @n2: A pointer to The second node
 */
void swp_node(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
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

	for (i = (*list)->next; i != NULL; i = k)
	{
		k = i->next;
		j = i->prev;
		while (j != NULL && i->n < j->n)
		{
			swp_node(list, &j, i);
			print_list((const listint_t *)*list);
			j = i->prev;
		}
		if (i->prev == NULL)
			*list = i;
	}
}
