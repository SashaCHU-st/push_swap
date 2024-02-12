/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:58:04 by aheinane          #+#    #+#             */
/*   Updated: 2024/02/12 11:56:32 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_node **stack_a, t_node **stack_b, size_t size_a, size_t group)
{
	int				temp;
	unsigned int	count;
	unsigned int	groups;
	unsigned int	i;

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

void	sort_100(t_node **stack_a, t_node **stack_b)
{
	unsigned int	size_a;

	size_a = ft_lstsize(*stack_a);
	sort(stack_a, stack_b, size_a, 8);
}

void	sort_500(t_node **stack_a, t_node **stack_b)
{
	unsigned int	size_a;

	size_a = ft_lstsize(*stack_a);
	sort(stack_a, stack_b, size_a, 10);
}
