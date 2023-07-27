#include "sort.h"

/**
 * swap1 - swaps nodes from left to right
 * @list: ptr to list
 * @head: ptr to head node
 * @aux: auxiliar ptr
 * Return: void
 */

void swap1(listint_t **list, listint_t *head, listint_t *aux)
{
	if (head->prev)
		head->prev->next = aux;
	else
		*list = aux;
	if (aux->next)
		aux->next->prev = head;
	head->next = aux->next;
	aux->prev = head->prev;
	aux->next = head;
	head->prev = aux;
	print_list(*list);

}

/**
 * swap2 - swaps nodes from right to left
 * @list: ptr to list
 * @head: ptr to head node
 * @aux: auxiliar ptr
 * Return: void
 */

void swap2(listint_t **list, listint_t *head, listint_t *aux)
{
	aux = head->prev;
	aux->next->prev = aux->prev;
	if (aux->prev)
		aux->prev->next = aux->next;
	else
		*list = aux->next;
	aux->prev = aux->next;
	aux->next = aux->next->next;
	aux->prev->next = aux;
	if (aux->next)
		aux->next->prev = aux;
	print_list(*list);
}

/**
 * cocktail_sort_list - sorts a dll in Cocktail sort ailgorithm
 * @list: ptr to the list head
 * Return: void
 **/

void cocktail_sort_list(listint_t **list)
{
	listint_t *head, *aux;
	int flag = 1;

	if (list)
	{
		head = *list;
		while (flag != 0)
		{
			flag = 0;
			while (head->next)
			{
				if (head->n > head->next->n)
				{
					aux = head->next;
					swap1(list, head, aux);
					flag = 1;
				}
				else
					head = head->next;
			}
			if (flag == 0)
				break;
			flag = 0;
			while (head->prev)
			{
				if (head->prev->n > head->n)
				{
					swap2(list, head, aux);
					flag = 1;
				}
				else
					head = head->prev;
			}

		}
	}
}
