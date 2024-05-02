#include "sort.h"

int __quick_sort_partition(int *array, size_t size,
							  int lower, int upper);
void __quick_sort_aux(int *array, size_t size,
					  size_t lower, size_t upper);
void swapint(int *n1, int *n2);

/**
 * quick_sort - Implementation of the
 * Quick sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 * Return: Nothing (viod)
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	__quick_sort_aux(array, size, 0, size - 1);
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

/**
 * __quick_sort_partition - Helper function to
 * implement the quick_sort function
 * @array: The array to sort
 * @size: The size of the array
 * @lower: The lower bound of the array
 * @upper: The upper bound of the array
 * Return: The index of the pivot as integer
 */

/*int
__quick_sort_partition(int *array, size_t size, size_t lower, size_t upper)
{
	size_t j;
	int pivot = array[upper];
	int i = lower - 1;

	for (j = lower; j <= upper - 1; j++)
	{
		if (pivot > array[j])
		{
			i++;
			swapint(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	//Get the pivot in place 
	swapint(&array[upper], &array[++i]);
	print_array(array, size);
	return ((size_t)i);
}*/
int __quick_sort_partition(int *array, size_t size, int lower, int upper)
{
	int pivot = array[upper];
	int i = (lower - 1), j;
  
	for (j = lower; j <= upper - 1; j++)
	{  
		if (array[j] < pivot)
		{
			i++;
			swapint(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	swapint(&array[i + 1], &array[upper]);
	print_array(array, size);
	return (i + 1);
}

/**
 * __quick_sort_aux - Helper function for
 * the quick sort
 * @array: The array to be sorted
 * @size: The size of the array
 * @lower: The lower index of the array
 * @upper: The upper index of the array
 * Return: Nothing (void)
 */

void __quick_sort_aux(int *array, size_t size, size_t lower, size_t upper)
{
	size_t partition;

	if (upper > lower)
	{
		partition = __quick_sort_partition(array, size, lower, upper);
		__quick_sort_aux(array, size, lower, partition - 1);
		__quick_sort_aux(array, size, partition + 1, upper);
	}
}
