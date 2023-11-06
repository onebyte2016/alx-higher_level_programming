#include "lists.h"
/**
 * is_palindrome - frees a listint_t list
 * @head: pointer to list to be freed
 * Return: void
 */
int is_palindrome(listint_t **head)
{
	if (head == NULL || *head == NULL)
		return (1);
	return (aux_palind(head, *head));
}
/**
 * aux_palind - frees a listint_t list
 * @head: pointer to list to be freed
 * @end: second parameter
 * Return: void
 */
int aux_palind(listint_t **head, listint_t *end)
	{
	if (end == NULL)
		return (1);
	if (aux_palind(head, end->next) && (*head)->n == end->n)
	{
		*head = (*head)->next;
		return (1);
	}
	return (0);
}
