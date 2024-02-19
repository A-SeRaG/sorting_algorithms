#include "sort.h"

void swaping(int *x, int *y)
{
    int current;

    current = *x;
    *x = *y;
    *y = current;
}

/**
 * selection_sort - Entry point for
 * @array: The array
 * @size: The number of entries
 * Return: The number of entries
*/
void selection_sort(int *array, size_t size)
{
    int *c
    size_t i, j;

    if (!array || !size)
        return;

        for (i = 0; i < size - 1; i++)
        {
            if ((array + i) != c)
            {
                swaping(array + i, c);
                print_array(array, size);
            }
            c = array + i;
            for (j = i + 1; j < size; j++)
                c = (array[j] < *c) ? (array + j) : c;
    }
}
