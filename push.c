/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:16:40 by aheinane          #+#    #+#             */
/*   Updated: 2024/01/07 13:37:31 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	push(int data, struct node **stack)
{
	struct node	*new;

	new = malloc(sizeof(new));
	if (new == NULL)
	{
		printf("overflow");
		exit(1);
	}
	new->data = data;
	new->link = NULL;
	new->link = *stack;
	*stack = new;
}

int	pop(struct node **stack)
{
	struct node	*temp;
	int			val;

	temp = *stack;
	val = temp->data;
	*stack = (*stack)->link;
	free(temp);
	temp = NULL;
	return (val);
}

void	pa(int data, struct node **stack)
{
	push(data, stack);
	printf("pa\n");
}

void	pb(int data, struct node **stack)
{
	push(data, stack);
	printf("pb\n");
}
