/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:10:54 by aheinane          #+#    #+#             */
/*   Updated: 2024/01/16 13:50:47 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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
	
	if (a < b && b < c && a < c)
		return ;
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
		while ((*stack_a)->rank < 3)
		{
			temp= pop(stack_a);
			pb(temp, stack_b);
			size--;
		}
		while ((*stack_a)->rank > 2)
		{
			ra(stack_a);
			break;
		}
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
	//more_then_three(stack_a, stack_b);
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
// void more_then_three(struct node **stack_a, struct node **stack_b) {
//     int size = ft_lstsize(*stack_a);

//     while (size > 3) {
//         while ((*stack_a)->rank > 1) {
//             ra(stack_a);
//             break;
//         }

//         while ((*stack_a)->rank < 2) {
//             int temp = pop(stack_a);
//             pb(temp, stack_b);
//             size--;
//         }
//     }
// }