/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 09:47:22 by aheinane          #+#    #+#             */
/*   Updated: 2024/01/22 15:13:29 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return(0);
}
int is_sign(char c)
{
	if (c == '-' || c <= '+')
		return (1);
	else
		return(0);
}
int if_number (char *argv)
{
	int i;
	
	i = 0;
	if (is_sign(argv[i]) && argv[i + 1] != '\0')
		i++;
	while(argv != '\0' && is_digit(argv[i]))
		i++;
	if(argv[i] != '\0' && !is_digit(argv[i]))
		return (0);
	return(1);
}
int good_input(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if(!if_number(argv[i]))
			return(0);
	}
	return (1);
}

int cmp(char *str1, char *str2)
{
	while (*str1 != '\0' && *str2 != '\0') 
	{
		if (*str1 != *str2)
			return 0; 
		str1++;
		str2++;
	}
	return (*str1 == '\0' && *str2 == '\0');
}
int not_duplicate(char *argv)
{
	int i;
	int j;
	 
	i = 1;
	while (argv[i])
	{
		j = 2;
		while (argv[j])
		{
			if(cmp (&argv[i],&argv[j]))
				return(0);
			j++;
		}
		i++;
	}
	return(1);
}
