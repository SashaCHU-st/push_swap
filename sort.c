/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:58:04 by aheinane          #+#    #+#             */
/*   Updated: 2024/01/11 18:33:36 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include "push_swap.h"

int the_biggest(struct node **stack)
{
	int max;
	
	max = INT_MIN;
	while ((*stack) != NULL)
	{
		if(max < (*stack)->rank)
			max = (*stack)->rank;
		(*stack)=(*stack)->link;
	}
	return (max);
}
void sort(struct node **stack_a, struct node **stack_b)
{
	int big_a;
	int big_b;

	big_a=the_biggest(stack_a);
	if ( !big_a)
	{
	printf("hello");
		int temp;
		temp= pop(stack_a);
		pb(temp, stack_b);
	}
	
	
	big_b=the_biggest(stack_b);
	//printf("A %d\n", big_a);
	///printf("B %d", big_b);
}