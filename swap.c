/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:20:16 by aheinane          #+#    #+#             */
/*   Updated: 2024/01/07 13:38:33 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	swap(struct node **stack)
{
	struct node	*temp;
	struct node	*newhead;

	temp = (*stack)->link->link;
	newhead = (*stack)->link;
	if (*stack == NULL || (*stack)->link == NULL)
		return ;
	newhead->link = (*stack);
	(*stack)->link = temp;
	(*stack) = newhead;
}

void	sa(struct node **stack)
{
	swap(stack);
	printf("sa\n");
}

void	sb(struct node **stack)
{
	swap(stack);
	printf("sb\n");
}

void	ss(struct node **stack_a, struct node **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	printf("ss\n");
}
