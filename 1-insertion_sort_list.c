#include "sort.h"

/**
 * swapint - Swaps two integers
 * @n1: The first integer
 * @n2: The second integer
 * Return: Nothing (void)
 */

void swapint(int *n1, int *n2);

/**
 * insertion_sort - Implementation for the
 * insertion sort algorithm with linked lists
 * @list: The head node of the list
 * Return: Nothing (void)
 */

void insertion_sort_list(listint_t **list)
{
	const int key;
	unsigned int i = 0, j = 0;
	listint_t *current, *backward;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		key = current->n;
		backward = current;
		current = current->next;
		while (backward)
		{
			if (backward->prev->n > backward->n)
			{
				swapint(&(backward->prev->n) > &(backward->n));
				if (!backward->prev)
					*list = backward;
				print_list((const listint_t *)*list);
			}
			else
				backward = backward->prev;
		}
	}
}

void swapint(int *n1, int *n2)
{
	int temp;

	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}
