/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:10:54 by aheinane          #+#    #+#             */
/*   Updated: 2024/01/11 13:17:49 by aheinane         ###   ########.fr       */
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
	c = (*stack)->link->link->rank;

	if (size == 2)
	{
		if ( b > c)
			sa(stack);
		else
			return;
	}
	else if (size == 3)
	{
		if ((a < b && b < c) || (a > b && b > c))
			return ;
		else if (c < b && b > a && a < c)
		{
			rra(stack);
			sa(stack);
		}
		else if (c > b && a < c && a > b)
			sa(stack);
		else if (c < b && c < a && a < b)
			rra(stack);
		else if (b < c && c < a && a > b)
			ra(stack);
		else if (c < b && c < a && a > b)
		{
			ra(stack);
			sa(stack);
		}
	}
}
void	two_sorting(struct node **stack)
{
	int	size;
	int	a;
	int	b;

	size = ft_lstsize(*stack);
	
	a = (*stack)->rank;
	b = (*stack)->link->rank;

	if (size == 2)
	{
		if ( a > b)
			sa(stack);
		else
			return;
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