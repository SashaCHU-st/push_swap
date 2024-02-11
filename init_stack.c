/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:34:12 by aheinane          #+#    #+#             */
/*   Updated: 2024/02/11 10:33:56 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	append_node(t_node **stack, int data)
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

void	assign_ranks(t_node **stack)
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

int	closest_number_in(t_node *stack_a, unsigned int target)
{
	unsigned int	closest;
	unsigned int	min_dif;
	unsigned int	diff;

	closest = stack_a->rank;
	min_dif = closest - target;
	while (stack_a)
	{
		diff = stack_a->rank - target;
		if (diff < min_dif || (diff == min_dif && stack_a->rank > closest))
		{
			min_dif = diff;
			closest = stack_a->rank;
		}
		stack_a = stack_a->link;
	}
	return (closest);
}

int	last_node(t_node *stack)
{
	if (stack == NULL)
		write(1, "Error: Linked list is empty.\n", 30);
	while (stack->link != NULL)
		stack = stack->link;
	return (stack->rank);
}

int	position(t_node *stack, unsigned int target)
{
	int		position;

	position = 1;
	while (stack != NULL)
	{
		if (stack->rank == target)
			return (position);
		stack = stack->link;
		position++;
	}
	return (-1);
}
