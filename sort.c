/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:58:04 by aheinane          #+#    #+#             */
/*   Updated: 2024/01/14 12:16:25 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include "push_swap.h"

// int the_biggest(struct node **stack)
// {
// 	int max;
	
// 	max = INT_MIN;
// 	while ((*stack) != NULL)
// 	{
// 		if(max < (*stack)->rank)
// 			max = (*stack)->rank;
// 		(*stack)=(*stack)->link;
// 	}
// 	return (max);
// }
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
	int size_b;
	int temp;
	size_b=ft_lstsize(*stack_b);
	int groups_b = size_b / 3;
	int remainder = size_b % 3;
	while (size_b)
	{
		int biggest_group = groups_b + remainder;
		printf("BIG GROUP -> %d",biggest_group);
		while(biggest_group)
		{
			temp= pop(stack_b);
			pa(temp, stack_a);
			biggest_group--;
			size_b--;
		}
			
		int medium=groups_b;
		while(medium)
		{
			printf("\n");
			temp= pop(stack_b);
			pa(temp, stack_a);
			medium--;
			size_b--;
		}
		int small=groups_b;
		while(small > 0)
		{
			temp= pop(stack_b);
			pa(temp, stack_a);
			small--;
			size_b--;
		}
}
}