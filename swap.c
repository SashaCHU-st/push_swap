/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:20:16 by aheinane          #+#    #+#             */
/*   Updated: 2024/02/11 10:36:32 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **stack)
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

void	sa(t_node **stack)
{
	swap(stack);
	printf("sa\n");
}

void	sb(t_node **stack)
{
	swap(stack);
	printf("sb\n");
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	printf("ss\n");
}
