/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:10:54 by aheinane          #+#    #+#             */
/*   Updated: 2024/01/11 15:32:06 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

void	three_sorting(struct node **stack)
{
	int	size;
	int	a;
	int	b;
	int	c;

	size = ft_lstsize(*stack);
	
	a = (*stack)->rank;
	b = (*stack)->link->rank;
	if (size == 2)
	{
		if ( a > b)
			sa(stack);
		return;
	}
	c = (*stack)->link->link->rank; 
	if (size == 3)
	{
		if (a < b && b < c && a < c)
			return ;
		if (c < b && b > a && a < c)
		{
			rra(stack);
			sa(stack);
		}
		if (c > b && a < c && a > b)
			sa(stack);
		if (c < b && c < a && a < b)
			rra(stack);
		if (b < c && c < a && a > b)
			ra(stack);
		if (c < b && c < a && a > b)
		{
			ra(stack);
			sa(stack);
		}
	}
}
void five_sort(struct node **stack_a, struct node **stack_b)
{
	int size;
	int temp;
	size = ft_lstsize(*stack_a);
	while (size > 3)
{
    while ((*stack_a)->rank < 3)
    {
        temp= pop(stack_a);
        pb(temp, stack_b);
        size--;
    }
    while ((*stack_a)->rank >= 2)
    {
        ra(stack_a);
        break;
    }
}
if (size == 3 )
    three_sorting(stack_a);
size = ft_lstsize(*stack_b);
if ((*stack_b)->rank == 1)
    sb(stack_b);
while (size > 0)
{
   temp= pop(stack_b);
    pa(temp, stack_a);
    size--; 
}
}
void four_sorting(struct node **stack_a, struct node **stack_b)
{
	int size;
	int temp;
	size = ft_lstsize(*stack_a);
	while (size > 3)
	{
		while ((*stack_a)->rank > 1)
		{
			ra(stack_a);
			break;
		}
		while ((*stack_a)->rank < 2)
		{
        	temp= pop(stack_a);
        	pb(temp, stack_b);
        	size--;
    	}
	}
	if (size == 3 )
		three_sorting(stack_a);
	temp= pop(stack_b);
    pa(temp, stack_a);
}