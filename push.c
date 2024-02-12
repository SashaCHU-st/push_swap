/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:16:40 by aheinane          #+#    #+#             */
/*   Updated: 2024/02/11 12:13:39 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(int rank, t_node **stack)
{
	struct node	*new;

	new = malloc(sizeof(struct node));
	if (new == NULL)
	{
		write(1, "overflow", 8);
		exit(1);
	}
	new->rank = rank;
	new->link = NULL;
	new->link = *stack;
	*stack = new;
}

int	pop(t_node **stack)
{
	struct node	*temp;
	int			val;

	temp = *stack;
	val = temp->rank;
	*stack = (*stack)->link;
	free(temp);
	temp = NULL;
	return (val);
}

void	pa(int rank, t_node **stack)
{
	push(rank, stack);
	write(1, "pa\n", 3);
}

void	pb(int rank, t_node **stack)
{
	push(rank, stack);
	write(1, "pb\n", 3);
}
