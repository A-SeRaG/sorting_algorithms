#include "sort.h"

void swp(int *array, size_t size, int *a, int *b);
int lomu_part(int *array, size_t size, int lo, int hi);
void lomu_sort(int *array, size_t size, int lo, int hi);

/**
 * swp - swap two integer number and print
 * @array: array to swap
 * @size: size of array
 * @a: address of first value
 * @b: address of second value
 * Return: void
*/

void swp(int *array, size_t size, int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	print_array((const int *)array, size);
}

/**
 * lomu_part - partitions the array
 * @array: array to sorted
 * @size: size of array
 * @lo: the low index
 * @hi: the high index
 * Return: int
*/

int lomu_part(int *array, size_t size, int lo, int hi)
{
	int i, j, pivot = array[hi];

	for (i = j = lo; j < hi; j++)
		if (array[j] < pivot)
			if (i < j)
				swp(array, size, &array[j], &array[i++]);
	return (i);
}

/**
 * lomu_sort - function sort array in quicksort algorithem
 * @array: array to sorted
 * @size: size of array
 * @lo: the low index
 * @hi: the high index
 * Return: void
*/

void lomu_sort(int *array, size_t size, int lo, int hi)
{
	if (lo < hi)
	{
		int S = lomu_part(array, size, lo, hi);

		lomu_sort(array, size, lo, S - 1);
		lomu_sort(array, size, S + 1, hi);
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
	if (!array || size < 2)
		return;
	lomu_sort(array, size, 0, size - 1);
}

