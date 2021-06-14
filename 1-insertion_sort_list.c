#include "sort.h"

/**
 * swap_nodes - swap between 2 nodes
 *
 * @slow: pointer to the first node to swap
 * @fast: pointer to the second node to swap
 * @list: double linked list
 * Return: void
 */
void swap_nodes(listint_t **slow, listint_t **fast, listint_t **list)
{
	listint_t *before, *after;

	/* restriction: if one of them is NULL */
	if (!(*slow) || !(*fast))
		return;

	/* input: before->slow->fast->after */
	/* output: before->fast->slow->after */
	before = (*slow)->prev;
	after = (*fast)->next;
	/* before -><- faster */
	if (before)
		before->next = (*fast);
	(*fast)->prev = before;
	/* fast -><- slow */
	(*fast)->next = (*slow);
	(*slow)->prev = (*fast);
	/* slow -><- after */
	(*slow)->next = after;
	if (after)
		after->prev = (*slow);
	/* changing memory address value of the pointers */
	*slow = *fast;
	*fast = (*slow)->next;
	/* CASE 0: start at the node -> set the head of LL */
	if (!before)
		*list = *slow;
}

/**
 * insertion_sort_list - sort the list like insertion
 *
 * @list: linked list
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *reverse_head, *tmp;

	if (!list || !(*list) || (!((*list)->prev) && !((*list)->next)))
		return;

	head = *list;
	head = head->next;
	while (head)
	{
		reverse_head = head->prev;
		/* go through the array since left to right until you find a less number */
		if (reverse_head->n > head->n)
		{
			/* when you find a small number, swap */
			swap_nodes(&reverse_head, &head, list);
			print_list(*list);
			/* through back the array until you find a less number */
			while (reverse_head->prev)
			{
				if ((reverse_head->n) < (reverse_head->prev->n))
				{
					/* create a tmp and swap again if it is necessary */
					tmp = reverse_head->prev;
					swap_nodes(&(tmp), &reverse_head, list);
					print_list(*list);
				}
				reverse_head = reverse_head->prev;
			}
		}
		head = head->next;
	}
}
