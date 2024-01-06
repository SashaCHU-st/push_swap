/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_from_first.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:15:46 by aheinane          #+#    #+#             */
/*   Updated: 2024/01/06 15:15:47 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	from_first_to_last_a(struct node **stack_a)
{
	struct node	*first;
	struct node	*last;

	first = *stack_a;
	last = *stack_a;
	if (*stack_a == NULL || (*stack_a)->link == NULL)
		return ;
	while (last->link != NULL)
		last = last->link;
	*stack_a = first->link;
	first->link = NULL;
	last->link = first;
	printf("\nra");
}

void	from_first_to_last_b(struct node **stack_b)
{
	struct node	*first;
	struct node	*last;

	first = *stack_b;
	last = *stack_b;
	if (*stack_b == NULL || (*stack_b)->link == NULL)
		return ;
	while (last->link != NULL)
		last = last->link;
	*stack_b = first->link;
	first->link = NULL;
	last->link = first;
	printf("\nrb\n");
}