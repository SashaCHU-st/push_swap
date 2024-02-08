/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 09:47:22 by aheinane          #+#    #+#             */
/*   Updated: 2024/02/08 14:22:53 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int cmp(char *str1, char *str2)
{
    int i = 0; 
    int j = 0;
    if (str1[i] == '+')
    {
        if (str2[j] != '+')
            i++;
    }
    else
    {
        if (str2[j] == '+')
            j++;
    }
    while (str1[i] != '\0' && str2[j] != '\0' && str1[i] == str2[j]) 
    {
        i++;
        j++;
    }
    return (str1[i] - str2[j]);
}
int	duplicated(struct node *stack, int n)
{
	while (stack)
	{
		if (stack->data == n)
			return (1);
		stack = stack->link;
	}
	return (0);
}
int is_sign(char c)
{
    if (c == '-' || c == '+')
        return (1);
    else
        return(0);
}
int zeros(char *argv)
{
    int i = 0;
    while (argv[i] && argv[i] == '0')
    {   
        i++;
        return(1);
    }
    return(0);  
}
int not_good_input(char *str)
{
    if (is_sign(*str))
        str++;
    if (*str < '0' || *str > '9')
        return (1);
    while (*str)
    {
        if (*str < '0' || *str > '9')
            return (1);
        str++;
    }
    return (0);
}
