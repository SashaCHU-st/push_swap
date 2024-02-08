/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:58:04 by aheinane          #+#    #+#             */
/*   Updated: 2024/02/08 17:08:32 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort(struct node **stack_a, struct node **stack_b)
{   
    int temp;
    unsigned int size_a;
    size_a=ft_lstsize(*stack_a);
    unsigned int count  =  size_a;
    unsigned int groups = (size_a - 3) / 8;
    unsigned int remainder = (size_a - 3) % 8 ;
    while (count > 3)
    {
        while (count)
        {
            if ((*stack_a)->rank <= groups)
            {
                temp= pop(stack_a);
                pb(temp, stack_b);
                count--;
            }
            else 
            {
                ra(stack_a);
                count--;
            }
        }
        push_elements_to_stack_b_2(stack_a, stack_b, groups, remainder);
        push_elements_to_stack_b_3(stack_a, stack_b, groups, remainder);
		int count4 = size_a -  (3*groups);
        while (count4)
        {
            if ((*stack_a)->rank <= (groups * 4 + remainder))
            {
                temp= pop(stack_a);
                pb(temp, stack_b);
                count4--;
            }
            else 
            {
                ra(stack_a);
                count4--;
            }
        }
		int count5 = size_a -  (4*groups);
        while (count5)
        {
            if ((*stack_a)->rank <= (groups * 5 + remainder))
            {
                temp= pop(stack_a);
                pb(temp, stack_b);
                count5--;
            }
            else 
            {
                ra(stack_a);
                count5--;
            }
        }
		int count6 = size_a -  (5*groups);
        while (count6)
        {
            if ((*stack_a)->rank <= (groups * 6 + remainder))
            {
                temp= pop(stack_a);
                pb(temp, stack_b);
                count6--;
            }
            else 
            {
                ra(stack_a);
                count6--;
            }
        }
		int count7 = size_a -  (6*groups);
        while (count7)
        {
            if ((*stack_a)->rank <= (groups * 7 + remainder))
            {
                temp= pop(stack_a);
                pb(temp, stack_b);
                count7--;
            }
            else 
            {
                ra(stack_a);
                count7--;
            }
        }
		int count8 = size_a -  (7*groups);
        while (count8)
        {
            if ((*stack_a)->rank <= (groups * 8 + remainder))
            {
                temp= pop(stack_a);
                pb(temp, stack_b);
                count8--;
            }
            else 
            {
                ra(stack_a);
                count8--;
            }
        }
    }
    three_sorting(stack_a);
}

void push_back_to_a(struct node **stack_a, struct node **stack_b)
{
    int size_a;
    int size_b;
    int temp;

    size_b = ft_lstsize(*stack_b);
	while (size_b )
	{
	int a = (*stack_b)->rank;
	int c = closest_number_in(*stack_a, a);
	int d = position(*stack_a, c);
    size_a = ft_lstsize(*stack_a);
	int part = size_a / 2;
	int remainder = size_a % 2;
		while(d <= (part + remainder) && d !=  1)
		{
			ra(stack_a);
			a = (*stack_b)->rank;
			c = closest_number_in(*stack_a, a);
			d = position(*stack_a, c);
		}
		while(d > part&& d != 1)
		{
			rra(stack_a);
			a = (*stack_b)->rank;
			c = closest_number_in(*stack_a, a);
			d = position(*stack_a, c);
		}
		while (d == 1)
		{
			temp= pop(stack_b);
			pa(temp, stack_a);
			size_b--;
			if (size_b == 0)
				break;
			d = 0;
		}
	}
	unsigned int first = (*stack_a)->rank;
	unsigned int last = last_node(*stack_a);
	while (first > last)
	{
		rra(stack_a);
		first = (*stack_a)->rank;
		last = last_node(*stack_a);
	}
}
