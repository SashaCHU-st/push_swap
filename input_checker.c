/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 09:47:22 by aheinane          #+#    #+#             */
/*   Updated: 2024/01/21 10:09:55 by aheinane         ###   ########.fr       */
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