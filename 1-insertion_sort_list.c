#include "sort.h"

/**
 * swap_nodes - Swaps two adjacent nodes in a doubly linked list
 * @list: Double pointer to the head of the list
 * @node1: First node to swap
 * @node2: Second node to swap (comes after node1)
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (!node1 || !node2)
		return;

	/* Update previous node's next pointer */
	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2; /* node1 was head, node2 becomes new head */

	/* Update next node's prev pointer */
	if (node2->next)
		node2->next->prev = node1;

	/* Swap the nodes */
	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using Insertion sort algorithm
 * @list: Double pointer to the head of the list
 *
 * Description: Prints the list after each swap
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *insertion_point;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		temp = current;
		current = current->next;
		insertion_point = temp->prev;

		/* Find the correct position to insert temp */
		while (insertion_point != NULL && insertion_point->n > temp->n)
		{
			/* Swap insertion_point with temp */
			swap_nodes(list, insertion_point, temp);
			
			/* Print the list after swap */
			print_list(*list);
			
			/* Move insertion_point backwards */
			insertion_point = temp->prev;
		}
	}
}
