/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:34:12 by aheinane          #+#    #+#             */
/*   Updated: 2024/01/17 17:25:13 by aheinane         ###   ########.fr       */
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
	new_node->rank = 0;
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
// int	position(struct node *stack, int i)
// {
// 	struct node	*temp;

// 	temp = stack;
// 	while (temp)
// 	{
// 		if (temp->rank == i)
// 			return (i);
// 		temp = temp->link;
// 		printf("%d", i);
// 	}
// 	return (-1);
// }
int position(struct node* stack, int target) 
{
    int position = 1;  // Start from the first node

    // Traverse the linked list
    while (stack != NULL) {
        // Check if the current node is the target node
        if (stack->rank == target) 
            return position;  
			printf("!!!!!!!!%d \n", position);
		// Return the position if found
        // Move to the next node
        stack = stack->link;
        position++;
    }
	printf("!!!!!!!!%d \n", position);
    return -1;
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
		printf("%d, %d\n", ptr->data, ptr->rank);
		ptr = ptr->link;
	}
}
