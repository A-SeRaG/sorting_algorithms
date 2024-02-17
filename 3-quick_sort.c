#include "sort.h"

/**
 * swp - swap two integer number
 * @array: array to sort
 * @size: size of array
 * @a: address of first value
 * @b: address of second value
 * Return: void
*/

void swp(int *array, size_t size, int *a, int *b)
{
	if (*a != *b)
	{
		*a += *b;
		*b = *a - *b;
		*a = *a - *b;
		print_array((const int *)array, size);
	}
}

/**
 * lomuto_partition - partitions the array
 * @array: array to sorted
 * @size: size of array
 * @lo: the low index
 * @hi: the high index
 * Return: size_t
*/

size_t lomuto_partition(int *array, size_t size, ssize_t lo, ssize_t hi)
{
	int i, j, pivot = array[hi];

	for (i = j = lo; j < hi; j++)
		if (array[j] < pivot)
			swp(array, size, &array[j], &array[i++]);
		swp(array, size, &array[i], &array[hi]);
	return (i);
}

/**
 * quicksort - function sort array in quicksort algorithem
 * @array: array to sorted
 * @size: size of array
 * @lo: the low index
 * @hi: the high index
 * Return: void
*/

void quicksort(int *array, size_t size, ssize_t lo, ssize_t hi)
{
	if (lo < hi)
	{
		size_t S = lomuto_partition(array, size, lo, hi);

		quicksort(array, size, lo, S - 1);
		quicksort(array, size, S + 1, hi);
	}
}

/**
 * quick_sort - calls quicksort
 * @array: array to sorted
 * @size: size of array
 * Return: void
*/

void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	quicksort(array, size, 0, size - 1);
}

