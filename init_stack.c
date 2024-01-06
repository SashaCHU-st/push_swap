/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:34:12 by aheinane          #+#    #+#             */
/*   Updated: 2024/01/06 15:37:36 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

void	append_node(struct node **head, int data)
{
	struct node	*last;
	struct node	*new_node;

	last = *head;
	new_node = malloc(sizeof(struct node));
	new_node->data = data;
	new_node->link = NULL;
	if (*head == NULL)
		*head = new_node;
	else
	{
		while (last->link != NULL) 
			last = last->link;
		last->link = new_node;
	}
}

//Delete later
void	print_data(struct node *head)
{
	struct node	*ptr;

	if (head == NULL)
		printf("Empty");
	ptr = NULL;
	ptr = head;
	while (ptr)
	{
		printf("%d\n", ptr->data);
		ptr = ptr->link;
	}
}