/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helping_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 09:43:36 by aheinane          #+#    #+#             */
/*   Updated: 2024/02/11 12:18:13 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_less_than_three_tob(t_node **stack_a, t_node **stack_b, int *size)
{
	int	temp;

	while ((*stack_a)->rank < 3)
	{
		temp = pop(stack_a);
		pb(temp, stack_b);
		(*size)--;
	}
}

void	rotate_stack_a_greater_than_two(t_node **stack_a)
{
	while ((*stack_a)->rank > 2)
	{
		ra(stack_a);
		break ;
	}
}

void	adjust_stack_a(t_node **stack_a)
{
	unsigned int	first;
	unsigned int	last;

	first = (*stack_a)->rank;
	last = last_node(*stack_a);
	while (first > last)
	{
		rra(stack_a);
		first = (*stack_a)->rank;
		last = last_node(*stack_a);
	}
}

void	process_argument(t_node **stack_a, char *arg)
{
	int		data;
	long	number;

	number = ft_atol(arg);
	data = ft_atol(arg);
	if (not_good_input(arg) || duplicated(*stack_a, data))
		error();
	if (number < INT_MIN || number > INT_MAX)
		error();
	append_node(stack_a, data);
}

void	process_stack(t_node **stack_a, t_node **stack_b, int size)
{
	unsigned int	size_a;

	assign_ranks(stack_a);
	if (is_sorted(*stack_a))
		return ;
	if (size == 6)
		five_sort(stack_a, stack_b);
	if (size == 5)
		four_sorting(stack_a, stack_b);
	else if (size == 4 || size == 3)
		three_sorting(stack_a);
	else if (size > 6 && size <= 101)
	{
		size_a = ft_lstsize(*stack_a);
		sort_100(stack_a, stack_b);
		push_back_to_a(stack_a, stack_b);
	}
	else if (size > 101)
	{
		size_a = ft_lstsize(*stack_a);
		sort_500(stack_a, stack_b);
		push_back_to_a(stack_a, stack_b);
	}
}
