#include "deck.h"

/**
 *_strcmp - compare each character between s1 and s2
 *@s1: string 1
 *@s2: string 2
 *Return: 0 is is equal or the difference of s1-s2
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	if (!s1[i] || !s2[i])
		return (0);
	return (s1[i] - s2[i]);
}

/**
 * card_number - compare each character between s1 and s2
 * @card: card
 * Return: number value to sort the deck of cards
 */
int card_number(const card_t *card)
{
	int i;
	char *card_list[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10",
				 "Jack", "Queen", "King"};

	for (i = 0; i < 13; i++)
		if (!_strcmp((char *)card_list[i], (char *)card->value))
			return ((i + 1) + (card->kind) * 20);
	return (-1);
}

/**
 * swap_nodes - swap between 2 nodes
 *
 * @slow: pointer to the first node to swap
 * @fast: pointer to the second node to swap
 * @list: double linked list
 * Return: void
 */
void swap_nodes(deck_node_t **slow, deck_node_t **fast, deck_node_t **list)
{
	deck_node_t *before, *after;

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
void cocktail_sort_list(deck_node_t **list)
{
	deck_node_t *slow, *fast;
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
			if (card_number(slow->card) > card_number(fast->card))
				swap_nodes(&slow, &fast, list);
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
			if (card_number(slow->card) < card_number(fast->card))
				swap_nodes(&fast, &slow, list);
			slow = slow->prev;
			fast = fast->prev;
			counter--;
		}
		/* set the node to left_limit ++ */
		slow = slow->next;
		fast = slow->next;
	}
}

/**
 * sort_deck - sort deck of card
 * @deck:double linnked list of deck card
 * Return: **deck sorted
 */
void sort_deck(deck_node_t **deck)
{
	if (!deck || !(*deck) || (!((*deck)->prev) && !((*deck)->next)))
		return;

	cocktail_sort_list(deck);
}
