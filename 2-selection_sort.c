#include "sort.h"

/**
 * swaping - Swap two
 * @x: first
 * @y: second
 */
void swaping(int *x, int *y)
{
	int t;

	t = *x;
	*x = *y;
	*y = t;
}

/**
 * selection_sort - Sort an array
 * @array: array
 * @size: size
 *
 * Return: array
 */
void selection_sort(int *array, size_t size)
{
	int *m;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		m = array + i;
		for (j = i + 1; j < size; j++)
			m = (array[j] < *m) ? (array + j) : m;

		if ((array + i) != m)
		{
			swaping(array + i, m);
			print_array(array, size);
		}
	}
}
