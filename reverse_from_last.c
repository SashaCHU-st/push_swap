/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_from_last.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:17:03 by aheinane          #+#    #+#             */
/*   Updated: 2024/01/06 15:19:21 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	from_last_to_first_a(struct node **stack_a)
{
	struct node	*last;
	struct node	*ptr1;

	last = NULL;
	ptr1 = *stack_a;
	if (*stack_a == NULL || (*stack_a)->link == NULL)
		return ;
	while (ptr1->link != NULL)
	{
		last = ptr1;
		ptr1 = ptr1->link;
	}
	last->link = NULL;
	ptr1->link = *stack_a;
	*stack_a = ptr1;
	printf("\nrra");
}

void	from_last_to_first_b(struct node **stack_b)
{
	struct node	*last;
	struct node	*ptr1;

	last = NULL;
	ptr1 = *stack_b;
	if (*stack_b == NULL || (*stack_b)->link == NULL)
		return ;
	while (ptr1->link != NULL)
	{
		last = ptr1;
		ptr1 = ptr1->link;
	}
	last->link = NULL;
	ptr1->link = *stack_b;
	*stack_b = ptr1;
	printf("\nrrb\n");
}