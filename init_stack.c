/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:34:12 by aheinane          #+#    #+#             */
/*   Updated: 2024/02/10 14:27:44 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

void	append_node(struct node **stack, int data)
{
	struct node	*last;
	struct node	*new_node;

	last = *stack;
	new_node = malloc(sizeof(struct node));
	new_node->data = data;
	new_node->link = NULL;
	if (*stack == NULL)
		*stack = new_node;
	else
	{
		while (last->link != NULL)
			last = last->link;
		last->link = new_node;
	}
}

void	assign_ranks(struct node **stack)
{
	struct node	*current;
	struct node	*index;

	current = *stack;
	while (current != NULL)
	{
		current->rank = 1;
		current = current->link;
	}
	current = *stack;
	while (current != NULL)
	{
		index = current->link;
		while (index != NULL)
		{
			if (current->data < index->data)
				index->rank++;
			else if (current->data > index->data)
				current->rank++;
			index = index->link;
		}
		current = current->link;
	}
}
int closest_number_in(struct node *stack_a, unsigned int target)
{
	unsigned int closest = stack_a->rank;
	unsigned int minimum_dif = closest - target;

	while (stack_a)
	{
		unsigned int diff = stack_a->rank - target;
		if(diff < minimum_dif || (diff == minimum_dif && stack_a->rank > closest))
		{
			minimum_dif = diff;
			closest= stack_a->rank;
		}
		stack_a= stack_a->link;
	}
	return(closest);
	
}
int last_node(struct node *stack)
{
	if (stack == NULL)
		printf("Error: Linked list is empty.\n");
    while (stack->link != NULL)
        stack = stack->link;
    return (stack->rank);
}

int position(struct node *stack, unsigned int target) 
{
	int position = 1;

	while (stack != NULL)
	{
		if (stack->rank == target)
			return (position);
		stack = stack->link;
		position++;
	}
	return (-1);
}

// //Delete later
// void	print_data(struct node *head)
// {
// 	struct node	*ptr;

// 	if (head == NULL)
// 		printf("Empty");
// 	ptr = NULL;
// 	ptr = head;
// 	while (ptr)
// 	{
// 		printf("%d, %d\n", ptr->data, ptr->rank);
// 		ptr = ptr->link;
// 	}
// }
