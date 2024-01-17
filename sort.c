/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:58:04 by aheinane          #+#    #+#             */
/*   Updated: 2024/01/17 17:11:24 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include "push_swap.h"

void sort(struct node **stack_a, struct node **stack_b)
{	
	int temp;
	int size_a;
	size_a=ft_lstsize(*stack_a);
	int count  =  size_a;
	int groups = (size_a - 3) / 3;
	int remainder = (size_a - 3) % 3;
	while (count > 3)
	{
		while(((*stack_a)->rank == size_a) || ((*stack_a)->rank == size_a - 1) || ((*stack_a)->rank == size_a - 2))
			ra(stack_a);
		while (count)
		{
			if ((*stack_a)->rank <= groups)
			{
				temp= pop(stack_a);
				pb(temp, stack_b);
				count--;
			}
			else 
			{
				ra(stack_a);
				count--;
			}
		}
		int count2 = size_a - groups;
		while (count2)
		{
			if ((*stack_a)->rank <= (groups * 2))
			{
				temp= pop(stack_a);
				pb(temp, stack_b);
				count2--;
			}
			else 
			{
				ra(stack_a);
				count2--;
			}
		}
		int count3 = size_a -  (2*groups);
		while (count3)
		{
			if ((*stack_a)->rank <= (groups * 3 + remainder))
			{
				temp= pop(stack_a);
				pb(temp, stack_b);
				count3--;
			}
			else 
			{
				ra(stack_a);
				count3--;
			}
		}
	}
	three_sorting(stack_a);
}

void push_back_to_a(struct node **stack_a, struct node **stack_b)
{
    int size_a;
    int size_b;
    int temp;

    size_a = ft_lstsize(*stack_a);
    size_b = ft_lstsize(*stack_b);
	int part= size_b / 2;

    while (size_b)
    {	
		int a = (*stack_a)->rank;
		int b = a - 1;
		int c = position(*stack_b, b);
		
		if (size_b == 1)
		{
				temp= pop(stack_b);
				pa(temp, stack_a);
				size_b=0;
				break;
		}
		while (c == b)
		{
			while ( c / 2 <= part)
			{
				rb(stack_b);
				if((*stack_b)->rank == b)
				{
					temp= pop(stack_b);
					pa(temp, stack_a);
					size_b--;
				}
				c--;
			}
			while ( c / 2 > part)
				{
					rrb(stack_b);
					if(c == 0)
				{
					temp= pop(stack_b);
					pa(temp, stack_a);
					size_b--;
				}
				c--;
				}
				
		}
		if (c == -1)
			rra(stack_a);
			
	}
}
			
		// int medium=groups_b;
		// while(medium)
		// {
		// 	if((*stack_b)->rank > (*stack_b)->link->rank)
		// 	{
		// 	temp= pop(stack_b);
		// 	pa(temp, stack_a);
		// 	medium--;
		// 	size_b--;
		// 	}
		// 	if((*stack_a)->rank > (*stack_a)->link->rank )
		// 		sa(stack_a);
		// 	else
		// 	 	sb(stack_b);
		// }
		// int small=groups_b;
		// while(small>0)
		// {
		// 	if (size_b == 1)
		// 	{
		// 		temp= pop(stack_b);
		// 		pa(temp, stack_a);
		// 		size_b=0;
		// 		break;
		// 	}
		// 	if((*stack_b)->rank > (*stack_b)->link->rank)
		// 	{
		// 	temp= pop(stack_b);
		// 	pa(temp, stack_a);
		// 	small--;
		// 	size_b--;
		// 	}
		// 	else if ((*stack_b)->rank < (*stack_b)->link->rank)
		// 	 	sb(stack_b);
		// 	if((*stack_a)->rank > (*stack_a)->link->rank )
		// 		sa(stack_a);
		// }
// }
// }