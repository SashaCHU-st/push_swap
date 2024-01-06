/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:16:40 by aheinane          #+#    #+#             */
/*   Updated: 2024/01/06 15:16:48 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	push_b(int data, struct node **stack_b)
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
	new->link = *stack_b;
	*stack_b = new;
	printf("\npb");
}

int	pop_a(struct node **stack_b)
{
	struct node	*temp;
	int			val;

	temp = *stack_b;
	val = temp->data;
	*stack_b = (*stack_b)->link;
	free(temp);
	temp = NULL;
	return (val);
}

void	push_a(int data, struct node **stack_a)
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
	new->link = *stack_a;
	*stack_a = new;
	printf("\npa");
}

int	pop_b(struct node **stack_a)
{
	struct node	*temp;
	int			val;

	temp = *stack_a;
	val = temp->data;
	*stack_a = (*stack_a)->link;
	free(temp);
	temp = NULL;
	return (val);
}