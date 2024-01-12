/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:58:04 by aheinane          #+#    #+#             */
/*   Updated: 2024/01/12 16:37:51 by aheinane         ###   ########.fr       */
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
	int i  =  size_a;
	int groups= (size_a- 3)/3;
	while (i > 3)
	{
		if(((*stack_a)->rank == size_a) || ((*stack_a)->rank == size_a - 1) || ((*stack_a)->rank == size_a - 2))
			ra(stack_a);
		else if ((*stack_a)->rank <= groups)
		{
			temp= pop(stack_a);
			pb(temp, stack_b);
			i--;
		}
		else if ((*stack_a)->rank <= (2*groups))
		{
			temp= pop(stack_a);
			pb(temp, stack_b);
			i--;
		}
		else
		{
			temp= pop(stack_a);
			pb(temp, stack_b);
			i--;
		}
		
	}
	
	printf("Groups %d\n", groups);
	three_sorting(stack_a);
}