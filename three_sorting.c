/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:10:54 by aheinane          #+#    #+#             */
/*   Updated: 2024/01/10 14:20:44 by aheinane         ###   ########.fr       */
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
		if ( c > b)
			sa(stack);
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
