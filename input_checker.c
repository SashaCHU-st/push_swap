/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 09:47:22 by aheinane          #+#    #+#             */
/*   Updated: 2024/02/06 18:26:39 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int is_sign(char c)
{
	if (c == '-' || c <= '+')
		return (1);
	else
		return(0);
}
int good_input(char *str)
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

int cmp(char *str1, char *str2)
{
	while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2) 
	{
		// if (*str1 != *str2)
		// 	return 1; 
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
int not_duplicate(char **argv)
{
	int i;
	int j;
	 
	i = 1;
	while (argv[i])
	{
		j = 1;
		while (argv[j])
		{
			if( j != i && cmp (argv[i],argv[j]) == 0)
				return(1);
			j++;
		}
		i++;
	}
	return(0);
}
