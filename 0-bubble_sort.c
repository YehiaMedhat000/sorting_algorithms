#include "sort.h"

/**
 * swapint - Swaps two integers
 * @n1: The first integer
 * @n2: The second integer
 * Return: Nothing (void)
 */

void swapint(int *n1, int *n2);

/**
 * bubble_sort - The bubble sort algorithm
 * implementation in c
 *
 */

void bubble_sort(int *array, size_t size)
{
	unsigned int swapped, i, j;

	if (size == 0 || size == 1)
		return;

	for (i = 0; i < size - 1; i++)
	{
        swapped = 0;
        for (j = 0; j < size - i - 1; j++)
		{
            if (array[j] > array[j + 1])
			{
                swapint(&array[j], &array[j + 1]);
				print_array(array, size);
                swapped++;
            }
        }
        if (swapped == 0)
            break;
	}
}

void swapint(int *n1, int *n2)
{
	int temp;

	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}
