/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:16:25 by aheinane          #+#    #+#             */
/*   Updated: 2024/02/05 18:04:32 by aheinane         ###   ########.fr       */
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

// void sorting(struct node **head)
// {
//     ///// swaping first two nodes
//     struct node * i;
// 	struct node * j;
//     int temp;
//     i = *head;
//     while (i->link!=NULL)
//     {
// 		j=i->link;
// 		while(j!=NULL)
// 		{
// 			if(i->rank > j->rank)
// 			{
// 				temp=i->rank;
// 				i->rank=j->rank;
// 				j->rank=temp;
// 			}
// 			j=j->link;
// 		}
//         i=i->link;
// }
// }
char	*free_function(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}
