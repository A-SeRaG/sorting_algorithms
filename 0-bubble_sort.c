#include "sort.h"


/**
 * bubble_sort - Entry point
 * @array: pointer
 * @size: size
 * Return: Always(0)
*/
void bubble_sort(int *array, size_t size)
{
	int temp;
	size_t i = 0, j;

	if (!array || !size)
	return;

	while (i < size)
	{
	for (j = 0; j < size - 1; j++)
	{
	if (array[j] > array[j + 1])
	{
	temp = array[j];
	array[j] = array[j + 1];
	array[j + 1] = temp;
	print_array(array, size);
	}
	}
	i++;
	}
}
