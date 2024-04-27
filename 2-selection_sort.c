#include "sort.h"

void swapint(int *n1, int *n2);

/**
 * selection_sort - Implementation for the
 * Selection sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 * Return: Nothing (void)
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx = 0;

	for (i = 0; i < size; i++)
	{
		min_idx = i;
		/* Search for the minimum at index min_idx */
		for (j = i; j < size; j++)
		{
			if (array[min_idx] > array[j])
				min_idx = j;
		}
		/* If the number is in its right place */
		if (min_idx != i)
		{
			swapint(&array[min_idx], &array[i]);
			print_array(array, size);
		}
	}
}

/**
 * swapint - Swaps two integers
 * @n1: The first integer
 * @n2: The second integer
 * Return: Nothing (void)
 */

void swapint(int *n1, int *n2)
{
	int temp;

	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}
