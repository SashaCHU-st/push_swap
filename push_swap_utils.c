/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:16:25 by aheinane          #+#    #+#             */
/*   Updated: 2024/02/10 16:05:49 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"

long	ft_atoi(const char *str)
{
	size_t	i;
	long	number;
	int		sign;

	i = 0;
	number = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 45)
		sign = -1;
	if (str[i] == 45 || str[i] == 43)
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		if (number > LONG_MAX / 10)
			return(LONG_MAX);
		number = number * 10;
		if (number > LONG_MAX - (str[i] - '0'))
			return(LONG_MAX);
		number = number + str[i] - '0';
		i++;
	}
	return (number * sign);
}
int	ft_lstsize(struct node *lst)
{
	int	i;

	i = 0;
	while (lst != 0)
	{
		i++;
		if (lst -> link)
			lst = lst -> link;
		else
			break ;
	}
	return (i);
}
int is_sorted(struct node *stack)
{
    while (stack != NULL && stack->link != NULL) 
	{
        if (stack->data > stack->link->data)
            return 0;
        stack = stack->link;
    }
    return 1;
}

char	*free_function(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}
int error()
{
	write(2, "Error\n", 6);
      exit(1);
}
void process_stack(struct node **stack_a, struct node **stack_b, int size)
{
    unsigned int size_a;
    assign_ranks(stack_a);
    if (is_sorted(*stack_a))
        return;
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
void process_argument(struct node **stack_a, char *arg)
{
    int data;
    long number;
    
    number = ft_atoi(arg);
    data = ft_atoi(arg);
    if (not_good_input(arg) || duplicated(*stack_a, data))
        error();
    if (number < INT_MIN || number > INT_MAX)
        error();
    append_node(stack_a, data);
}

void push_elements_to_stack_b_n(struct node **stack_a, struct node **stack_b, unsigned int num_groups, unsigned int size_a)
{
	int temp;
    int count;
    int groups;
    int remainder;

    groups = size_a/ (num_groups);
    remainder = size_a % (num_groups);
    count = size_a - ((num_groups - 1) * groups);
    while (count > 0) 
	{
        if ((*stack_a)->rank <= (groups * num_groups + remainder))
		{
            temp = pop(stack_a);
            pb(temp, stack_b);
        }
		else 
            ra(stack_a);
        count--;
    }
}
void adjust_stack_a(struct node **stack_a)
{
    unsigned int first;
    unsigned int last;
    
    first = (*stack_a)->rank;
    last = last_node(*stack_a);
    while (first > last)
    {
        rra(stack_a);
        first = (*stack_a)->rank;
        last = last_node(*stack_a);
    }
}
void process_nodes(struct node **stack_a, struct node **stack_b, unsigned int *count, unsigned int groups, unsigned int i, unsigned int remainder)
{
    int temp;
    while (*count)
    {
        if ((*stack_a)->rank <= (groups * (i + 1) + remainder))
        {
            temp = pop(stack_a);
            pb(temp, stack_b);
        }
        else
            ra(stack_a);
        (*count)--;
    }
}