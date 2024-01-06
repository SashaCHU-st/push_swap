/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:20:16 by aheinane          #+#    #+#             */
/*   Updated: 2024/01/06 15:25:46 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	swap_a(struct node **stack_a)
{
	struct node	*temp;
	struct node	*newhead;

	temp = (*stack_a)->link->link;
	newhead = (*stack_a)->link;
	if (*stack_a == NULL || (*stack_a)->link == NULL)
		return ;
	newhead->link = (*stack_a);
	(*stack_a)->link = temp;
	(*stack_a) = newhead;
	printf("sa\n");
}

void	swap_b(struct node **stack_b)
{
	struct node	*temp;
	struct node	*newhead;

	temp = (*stack_b)->link->link;
	newhead = (*stack_b)->link;
	if (*stack_b == NULL || (*stack_b)->link == NULL)
		return ;
	newhead->link = (*stack_b);
	(*stack_b)->link = temp;
	(*stack_b) = newhead;
	printf("sb\n");
}