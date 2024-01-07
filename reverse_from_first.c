/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_from_first.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:15:46 by aheinane          #+#    #+#             */
/*   Updated: 2024/01/07 13:39:28 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	from_first_to_last(struct node **stack)
{
	struct node	*first;
	struct node	*last;

	first = *stack;
	last = *stack;
	if (*stack == NULL || (*stack)->link == NULL)
		return ;
	while (last->link != NULL)
		last = last->link;
	*stack = first->link;
	first->link = NULL;
	last->link = first;
}

void	ra(struct node **stack)
{
	from_first_to_last(stack);
	printf("ra\n");
}

void	rb(struct node **stack)
{
	from_first_to_last(stack);
	printf("rb\n");
}

void	rr(struct node **stack_a, struct node **stack_b)
{
	from_first_to_last(stack_a);
	from_first_to_last(stack_b);
	printf("rr\n");
}
