#include "sort.h"

/**
 * swaping - Swap
 * @x: first
 * @y: second
 */
void swaping(int *x, int *y)
{
	int curunt;

	curunt = *x;
	*x = *y;
	*y = curunt;
}

/**
 * selection_sort - bitc
 * @array: array
 * @size: The
 * Return: suc
 */
void selection_sort(int *array, size_t size)
{
	int *nolds;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		nolds = array + i;
		for (j = i + 1; j < size; j++)
			nolds = (array[j] < *nolds) ? (array + j) : nolds;

		if ((array + i) != nolds)
		{
			swaping(array + i, mnolds);
			print_array(array, size);
		}
	}
}
