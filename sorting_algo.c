/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 09:35:36 by aheinane          #+#    #+#             */
/*   Updated: 2024/02/11 09:36:53 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_to_top(t_node **stack_a, t_node **stack_b, int position)
{
	int	close;
	int	part;

	part = ft_lstsize(*stack_a) / 2;
	while (position <= part && position != 1)
	{
		ra(stack_a);
		close = find_closest_number(stack_a, (*stack_b)->rank);
		position = calculate_position(stack_a, close);
	}
	while (position > part && position != 1)
	{
		rra(stack_a);
		close = find_closest_number(stack_a, (*stack_b)->rank);
		position = calculate_position(stack_a, close);
	}
}

int	find_closest_number(t_node **stack_a, int rank_b)
{
	int	number;

	number = closest_number_in(*stack_a, rank_b);
	return (number);
}

int	calculate_position(t_node **stack_a, int closest_number)
{
	int	pos;

	pos = position(*stack_a, closest_number);
	return (pos);
}

void	push_back_to_a(t_node **stack_a, t_node **stack_b)
{
	int	size_b;
	int	temp;
	int	closest_number;
	int	position;

	size_b = ft_lstsize(*stack_b);
	while (size_b)
	{
		closest_number = find_closest_number(stack_a, (*stack_b)->rank);
		position = calculate_position(stack_a, closest_number);
		rotate_to_top(stack_a, stack_a, position);
		while (position == 1)
		{
			temp = pop(stack_b);
			pa(temp, stack_a);
			size_b--;
			if (size_b == 0)
				break ;
			position = 0;
		}
	}
	adjust_stack_a (stack_a);
}
