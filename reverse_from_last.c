/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_from_last.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:17:03 by aheinane          #+#    #+#             */
/*   Updated: 2024/02/11 10:36:13 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	from_last_to_first(t_node **stack)
{
	struct node	*last;
	struct node	*ptr1;

	last = NULL;
	ptr1 = *stack;
	if (*stack == NULL || (*stack)->link == NULL)
		return ;
	while (ptr1->link != NULL)
	{
		last = ptr1;
		ptr1 = ptr1->link;
	}
	last->link = NULL;
	ptr1->link = *stack;
	*stack = ptr1;
}

void	rra(t_node **stack)
{
	from_last_to_first(stack);
	printf("rra\n");
}

void	rrb(t_node **stack)
{
	from_last_to_first(stack);
	printf("rrb\n");
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	from_last_to_first(stack_a);
	from_last_to_first(stack_b);
	printf("rrr\n");
}
