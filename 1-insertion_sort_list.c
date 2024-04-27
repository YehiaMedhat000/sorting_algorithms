#include "sort.h"

void swapnodes(listint_t *node1, listint_t *node2);

/**
 * insertion_sort_list - Implementation for the
 * insertion sort algorithm with linked lists
 * @list: The head node of the list
 * Return: Nothing (void)
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *moving = (*list)->next, *stationary;
	unsigned int i = 0, j = 0;

	if (!list || !*list || !(*list)->next)
		return;

	while (moving)
	{
		i++;
		if (moving->n < moving->prev->n)
		{
			swapnodes(moving->prev, moving);
			if (!moving->prev)
				*list = moving;
			print_list((const listint_t *)*list);

			stationary = moving->next;
			for (j = i - 1; j > 0 && moving->prev ; j--)
			{
				if (moving->n < moving->prev->n)
				{
					swapnodes(moving->prev, moving);
					/* If swapped with the head */
					if (!moving->prev)
						*list = moving;
					print_list((const listint_t *)*list);
				}
				else
					break;
			}
			moving = stationary;
		}
		else
			moving = moving->next;
	}
}

/**
 * swapnodes - Swaps two nodes in
 * a linked list
 * @node1: The 1st node
 * @node2: The 2nd node
 * Return: Nothing (void)
 */

void swapnodes(listint_t *node1, listint_t *node2)
{
	/*
	 * Cutting the connections between
	 * the swapped nodes
	 */
	node1->next = node2->next;
	node2->prev = node1->prev;

	/* Reconnecting the nodes in order */
	node1->prev = node2;
	node2->next = node1;

	if (node1->next)
	{
		/*
		 * For the node next to node1
		 * but its prev still pointing to node2
		 */
		node1->next->prev = node1;
	}
	if (node2->prev)
	{
		/*
		 * For the node previous to node2
		 * but its next still pointing to node1
		 */
		node2->prev->next = node2;
	}
}
