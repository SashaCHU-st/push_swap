/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 11:54:34 by aheinane          #+#    #+#             */
/*   Updated: 2024/02/11 11:59:31 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_node **stack)
{
	t_node	*temp;
	t_node	*current;

	current = *stack;
	if (!stack)
		return ;
	while (current)
	{
		temp = current->link;
		free(current);
		current = temp;
	}
	*stack = NULL;
}
