/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:58:04 by aheinane          #+#    #+#             */
/*   Updated: 2024/02/10 17:53:18 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_node **stack_a, t_node **stack_b,size_t size_a, size_t group)
{
	int temp;
	unsigned int count;
	unsigned int groups;
	unsigned int i;
	
	count = size_a;
	groups = (size_a - 3) / group;
	i = 0;
	while (count > 3 && i < group)
	{
		while (count)
		{
			if ((*stack_a)->rank <= (groups * (i + 1) + (size_a - 3) % group))
			{
				temp = pop(stack_a);
				pb(temp, stack_b);
			} 
			else
				ra(stack_a);
			count--;
		}
		i++;
		count = ft_lstsize(*stack_a);
	}
	three_sorting(stack_a);
}

void	sort_100(struct node **stack_a, struct node **stack_b)
{
	unsigned int size_a = ft_lstsize(*stack_a);
	sort(stack_a, stack_b,size_a, 8);
}

void	sort_500(struct node **stack_a, struct node **stack_b)
{
	unsigned int size_a = ft_lstsize(*stack_a);
	sort(stack_a, stack_b,size_a, 10);
}

void	rotate_to_top(struct node **stack_a,struct node **stack_b, int position)
{
	int close;
	int part;
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
int	find_closest_number(struct node **stack_a, int rank_b)
{
	int number;
	number = closest_number_in(*stack_a, rank_b);
	return (number);
}
int	calculate_position(struct node **stack_a, int closest_number)
{
	int pos;
	pos = position(*stack_a, closest_number);
	return (pos);
}

void	push_back_to_a(struct node **stack_a, struct node **stack_b)
{
	int size_b;
	int temp;
	int closest_number;
	int position;

	size_b = ft_lstsize(*stack_b);
	while (size_b)
	{
		closest_number = find_closest_number(stack_a, (*stack_b)->rank);
		position = calculate_position(stack_a, closest_number);
		rotate_to_top(stack_a, stack_a, position);
		while (position == 1)
		{
			temp= pop(stack_b);
			pa(temp, stack_a);
			size_b--;
			if (size_b == 0)
				break;
			position = 0;
		}
	}
adjust_stack_a(stack_a);
}

