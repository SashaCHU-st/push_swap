/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:29:05 by aheinane          #+#    #+#             */
/*   Updated: 2024/02/08 14:19:19 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
# include <limits.h>
#include "push_swap.h"

int main(int argc, char **argv)
{

struct node *stack_a = NULL;
struct node *stack_b = NULL;
char    **array;
int i = 1;
int data;

if(argc < 2)
        return (0);
if (argc == 2)
{
    int j = 0; 
    array = ft_split(argv[i], ' ');
    if (!array[j] ||!array )
    {
        write(2, "Error\n", 6);
        exit(1);
    }
    while (array[j])
    {
        if(not_good_input(array[j]))
        {
            write(2, "Error\n", 6);
            return(0);
        }
        
        long number = ft_atoi(argv[i]);
        if (number < INT_MIN || number > INT_MAX)
        {
            write(2, "Error\n", 6);
            return(0);
        }
        data = ft_atoi(array[j]);
        if(duplicated(stack_a, data))
        {
            write(2, "Error\n", 6);
            return(0);
        }
        append_node(&stack_a, data);
        j++;
    }
    free(array);
    assign_ranks(&stack_a);
    if (j == 5)
        five_sort(&stack_a, &stack_b);
    if (j == 4)
        four_sorting(&stack_a, &stack_b);
    if (j == 3 || j == 2)
        three_sorting(&stack_a);
    else if (j > 5)
    {
        sort(&stack_a, &stack_b);
        push_back_to_a(&stack_a, &stack_b);
    }
}
else
{
    int j = 1; 
    while (j < argc)
    {
        if(not_good_input(argv[j]))
        {
            write(2, "Error\n", 6);
            return(0);
        }
        data = ft_atoi(argv[j]);
        long number = ft_atoi(argv[i]);
        if (number < INT_MIN || number > INT_MAX)
        {
            write(2, "Error\n", 6);
            return(0);
        }
        if(duplicated(stack_a, data))
        {
            write(2, "Error\n", 6);
            return(0);
        }
        append_node(&stack_a, data);
        j++;
    }
    assign_ranks(&stack_a);
    if (j == 6)
        five_sort(&stack_a, &stack_b);
    if (j == 5)
       four_sorting(&stack_a, &stack_b);
    if (j == 4 || j == 3)
        three_sorting(&stack_a);
    else if (j > 6)
    {
        sort(&stack_a, &stack_b);
        push_back_to_a(&stack_a, &stack_b);
    }
}
/////Coment this!!!!!!!!!!!!!!!!!!!!!!
// printf("//////////////////////Stack_b////////////////////////\n");
// print_data(stack_b);
// printf("/////////////////////////Stack_a////////////////////////\n");
// print_data(stack_a);

return(0);
}
