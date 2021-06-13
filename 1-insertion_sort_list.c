#include "sort.h"

/**
 * insertion_sort_list - sort the list like insertion
 *
 * @list: linked list
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *reverse_head, *insert, *before, *after;
	int key;

	if (!(*list) || !(list) || !(*list)->next)
		return;

	head = *list;
	head = head->next;
	while (head)
	{
		key = head->n;
		reverse_head = head->prev;
		/* unsorted array */
		while (reverse_head && (key < (reverse_head->n)))
		{
			insert = reverse_head->next;
			/* all cases */
			before = reverse_head->prev;
			if (insert)
				after = insert->next;
			else
				after = NULL;
			if (before)
				before->next = insert;
			insert->prev = before;
			insert->next = reverse_head;
			reverse_head->prev = insert;
			reverse_head->next = after;
			/* when there are not at the final */
			if (after)
				after->prev = reverse_head;
			/* case at start of node */
			if (!before)
				*list = insert;
			reverse_head = before;
			print_list(*list);
		}
		head = head->next;
	}
}
