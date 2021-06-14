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
 * cocktail_sort_list - improve of bubble sort algorithm
 * go through the array since head to tail take the biggest n
 * return since the tail - 1 until head + 1 bringing the small n
 *
 * @list: double linked list
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *slow, *fast;
	int left_limit = -1, right_limit = -1, counter = 0;

	if (!list || !(*list) || (!((*list)->prev) && !((*list)->next)))
		return;

	/* first while, bring the biggest number to the last n! time*/
	slow = *list;
	fast = (*list)->next;
	while (left_limit <= right_limit)
	{
		left_limit++;
		while (slow && fast && counter != right_limit)
		{
			if (slow->n > fast->n)
				swap_nodes(&slow, &fast, list), print_list(*list);
			slow = slow->next;
			fast = fast->next;
			counter++;
		}
		if (left_limit == 0)
			right_limit = counter;
		right_limit--;
		/* second while, bring the lest number to the first, set nodes (n-1)! */
		slow = slow->prev;
		fast = slow->prev;
		while (slow && fast && counter >= left_limit)
		{
			if (slow->n < fast->n)
				swap_nodes(&fast, &slow, list), print_list(*list);
			slow = slow->prev;
			fast = fast->prev;
			counter--;
		}
		/* set the node to left_limit ++ */
		slow = slow->next;
		fast = slow->next;
	}
}
