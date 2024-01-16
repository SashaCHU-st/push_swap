/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:58:04 by aheinane          #+#    #+#             */
/*   Updated: 2024/01/16 16:57:53 by aheinane         ###   ########.fr       */
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
// void	position(struct node **stack)
// {
// 	struct node	*temp;
// 	int		i;

// 	temp = *stack;
// 	i = 0;
// 	while (temp)
// 	{
// 		temp->pos = i;
// 		temp = temp->link;
// 		i++;
// 	}
// }
// void push_back_to_a(struct node **stack_a, struct node **stack_b)
// {
//     int size_a;
//     int size_b;
//     int temp;

// 	int a = ft_lstlast(*stack_a);
//     size_a = ft_lstsize(*stack_a);
//     size_b = ft_lstsize(*stack_b);

//     while (size_b)
//     {
//         if (size_b == 1)
//         {
//             temp = pop(stack_b);
//             printf("1");
//             pa(temp, stack_a);
//             size_b = 0;
//             break;
//         }

//         while (size_b > 1 && ((*stack_b)->rank < (*stack_a)->rank) && ((*stack_b)->rank > (*stack_a)->link==NULL))
//         {
//             temp = pop(stack_b);
//             printf("2");
//             pa(temp, stack_a);
//             size_b--;
// 			size_a++;
//         }

//         while (size_b > 1 && ((*stack_a)->rank ==NULL < (*stack_a)->rank) && ((*stack_a)->rank ==NULL > (*stack_b)->rank))
//         {
//             printf("3");
//             rra(stack_a);
//         }

//         while (size_b > 1 && ((*stack_b)->rank < (*stack_a)->rank) && ((*stack_a)->rank > (*stack_a)->rank == NULL))
//         {
//             printf("4");
//             ra(stack_a);
//         }

//         while (size_b > 1 && ((*stack_b)->rank < (*stack_a)->rank))
//         {
//             temp = pop(stack_b);
//             pa(temp, stack_a);
//             printf("5");
//             size_b--;
// 			size_a++;
//         }

//         while (size_b > 1 && ((*stack_b)->rank > (*stack_a)->rank))
//         {
//             ra(stack_a);
//             printf("6");
//         }
//     }
// }
			
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