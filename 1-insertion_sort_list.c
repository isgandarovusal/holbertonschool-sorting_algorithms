#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using Insertion sort algorithm
 * @list: Double pointer to the head of the list
 *
 * Description: Prints the list after each swap
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		insert = current;
		current = current->next;

		while (insert->prev != NULL && insert->prev->n > insert->n)
		{
			tmp = insert->prev;

			if (tmp->prev)
				tmp->prev->next = insert;
			else
				*list = insert;

			if (insert->next)
				insert->next->prev = tmp;

			tmp->next = insert->next;
			insert->prev = tmp->prev;
			tmp->prev = insert;
			insert->next = tmp;

			print_list(*list);
		}
	}
}
