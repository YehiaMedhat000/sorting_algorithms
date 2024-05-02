size_t __quick_sort_partition(int *array, size_t size, size_t lower, size_t upper)
{
	size_t i, j;
	int *pivot = array + upper;

	for (i = lower; i < upper && array[i] < *pivot; i++)
		;

	for (j = upper; array[j] > *pivot && j > lower; j--)
		;

	if (i < j)
	{
		swapint(array + i, pivot);
		print_array(array, size);
	}
	swapint(array + lower, array + j);
	return (j);
}
