#include "main.h"

/**
 * 0-print_list.c function that prints all the elements of a list_t list.
 *
 *Return: always 0
 */
 int main(void)
 {
	list_t *head;
	list_t *new;
	list_t hello = {"World", 5, NULL};
	size_t n;

	head = &hello;
	new = malloc(sizeof(list_t));
	if (new == NULL)
	{
		printf("Error\n");
		return (1);
	}

	str = strdup("Hello");
	len = 5;
	next = head;
	head = new;
	n = print_list(head);
	printf("%lu elements\n", n);

	printf("\n");
	free(str);
	str = NULL;
	n = print_list(head);
	printf("%lu elements\n", n);

	free;
	return (0);
 }
