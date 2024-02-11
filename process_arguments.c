/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_arguments.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:38:29 by aheinane          #+#    #+#             */
/*   Updated: 2024/02/11 10:48:15 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(int argc, char **argv, t_node **stack_a, t_node **stack_b)
{
	if (argc == 2)
		arg_split(argv, stack_a, stack_b);
	else
		arg_no_split(argc, argv, stack_a, stack_b);
}

void	arg_split(char **argv, t_node **stack_a, t_node **stack_b)
{
	char	**array;
	int		j;

	j = 0;
	array = ft_split(argv[1], ' ');
	if (!array || !array[0])
		error();
	while (array[j])
	{
		process_argument(stack_a, array[j]);
		j++;
	}
	free(array);
	process_stack(stack_a, stack_b, j + 1);
}

void	arg_no_split(int argc, char **argv, t_node **stack_a, t_node **stack_b)
{
	int	j;

	j = 1;
	while (j < argc)
	{
		process_argument(stack_a, argv[j]);
		j++;
	}
	process_stack(stack_a, stack_b, j);
}
