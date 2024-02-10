/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:58:04 by aheinane          #+#    #+#             */
/*   Updated: 2024/02/10 15:08:32 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void sort(struct node **stack_a, struct node **stack_b,unsigned int size_a, unsigned int group_size)
{
    unsigned int count;
    unsigned int groups;
    unsigned int remainder;
    unsigned int i;
	
	count = size_a;
	groups = (size_a - 3) / group_size;
	remainder = (size_a - 3) % group_size;
	i = 0;
    while (count > 3)
	{
        while (i < group_size)
		{
            count = ft_lstsize(*stack_a);
            process_nodes(stack_a, stack_b, &count, groups, i, remainder);
            i++;
        }
    }
    three_sorting(stack_a);
}
 
void sort_100(struct node **stack_a, struct node **stack_b, unsigned int size_a)
{
    sort(stack_a, stack_b,size_a, 8);
}

void sort_500(struct node **stack_a, struct node **stack_b, unsigned int size_a)
{
    sort(stack_a, stack_b,size_a, 10);
}
void rotate_to_top(struct node **stack_a,struct node **stack_b, int position) 
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
int find_closest_number(struct node **stack_a, int rank_b)
{
	int number;
	number = closest_number_in(*stack_a, rank_b);
    return (number);
}
int calculate_position(struct node **stack_a, int closest_number)
{
	int pos;
	pos = position(*stack_a, closest_number);
    return (pos);
}

void push_back_to_a(struct node **stack_a, struct node **stack_b)
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

