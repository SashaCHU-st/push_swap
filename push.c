/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:16:40 by aheinane          #+#    #+#             */
/*   Updated: 2024/01/10 16:24:35 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	push(int rank, struct node **stack)
{
	struct node	*new;

	new = malloc(sizeof(new));
	if (new == NULL)
	{
		printf("overflow");
		exit(1);
	}
	new->rank = rank;
	new->link = NULL;
	new->link = *stack;
	*stack = new;
}

int	pop(struct node **stack)
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

void	pa(int rank, struct node **stack)
{
	push(rank, stack);
	printf("pa\n");
}

void	pb(int rank, struct node **stack)
{
	push(rank, stack);
	printf("pb\n");
}
