/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:58:04 by aheinane          #+#    #+#             */
/*   Updated: 2024/01/19 18:23:12 by aheinane         ###   ########.fr       */
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
    unsigned int size_a;
    size_a=ft_lstsize(*stack_a);
    unsigned int count  =  size_a;
    unsigned int groups = (size_a - 3) / 3;
    unsigned int remainder = (size_a - 3) % 3;
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
	int d = 1;

    size_b = ft_lstsize(*stack_b);
	while (size_b )
	{
	int a = (*stack_b)->rank;
	int c = closest_number_in_a(*stack_a, a);
	d = position(*stack_a, c);
    size_a = ft_lstsize(*stack_a);
	int part = size_a / 2;
	int remainder = size_a % 2;
		// if (size_b == 1)
		// {
		// 		temp= pop(stack_b);
		// 		pa(temp, stack_a);
		// 		size_b=0;
		// }
		while(d <= (part + remainder) && d !=  1)
		{
			ra(stack_a);
			a = (*stack_b)->rank;
			c = closest_number_in_a(*stack_a, a);
			d = position(*stack_a, c);
		}
		while(d > part&& d != 1)
		{
			rra(stack_a);
			a = (*stack_b)->rank;
			c = closest_number_in_a(*stack_a, a);
			d = position(*stack_a, c);
		}
		while (d == 1)
		{
			temp= pop(stack_b);
			pa(temp, stack_a);
			size_b--;
		//	printf("hello");
			if (size_b == 0)
				break;
			d = 0;
		}
	}	
}



		/////////////OLD VERSION
	// 	int a = (*stack_b)->rank;
	// int b = a - 1;
	// int c = position(*stack_a, b);
	// 	if (c != 1)
	// 	{
	// 		while (c <= part && c > 1)
	// 		{
	// 			rb(stack_b);
	// 			c--;
	// 		}
	// 		while ( c > part && c > 1)
	// 		{
	// 			rrb(stack_b);
	// 			c--;
	// 		}
	// 	}
	// 	if(size_b > 1 && c == 1)
	// 	{
	// 		temp= pop(stack_b);
	// 		pa(temp, stack_a);
	// 		size_b--;
	// 	}
	
	// if (c == -1)
	// 	rra(stack_a);







			
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