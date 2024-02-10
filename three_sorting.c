/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:10:54 by aheinane          #+#    #+#             */
/*   Updated: 2024/02/10 14:52:09 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

void two_sorting(struct node **stack) 
{
	int	a;
	int	b;

	a = (*stack)->rank;
	b = (*stack)->link->rank;

	if (a > b) 
		sa(stack);
	return ;
}

void three_sorting_case(struct node **stack) 
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->rank;
	b = (*stack)->link->rank;
	c = (*stack)->link->link->rank;
	
	if (c < b && b > a && a < c) 
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

void three_sorting(struct node **stack) 
{
	int size;

	size = ft_lstsize(*stack);
	if (size == 2)
		two_sorting(stack);
	else if (size == 3)
		three_sorting_case(stack);
}

void five_sort(struct node **stack_a, struct node **stack_b)
{
	int size;
	int temp;
	
	size = ft_lstsize(*stack_a);
	while (size > 3)
	{
		push_less_than_three_to_stack_b(stack_a, stack_b, &size);
    	rotate_stack_a_greater_than_two(stack_a);
	}
if (size == 3)
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
	if (size == 3)
		three_sorting(stack_a);
	temp= pop(stack_b);
	pa(temp, stack_a);
}
void push_less_than_three_to_stack_b(struct node **stack_a, struct node **stack_b, int *size)
{
    int temp;
    while ((*stack_a)->rank < 3)
	{
        temp = pop(stack_a);
        pb(temp, stack_b);
        (*size)--;
    }
}

void rotate_stack_a_greater_than_two(struct node **stack_a)
{
    while ((*stack_a)->rank > 2)
	{
        ra(stack_a);
        break;
    }
}
