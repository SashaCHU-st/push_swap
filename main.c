/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:29:05 by aheinane          #+#    #+#             */
/*   Updated: 2024/02/05 18:30:38 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
# include <limits.h>
#include "push_swap.h"

int main(int argc, char *argv[])
{

struct node *stack_a = NULL;
struct node *stack_b = NULL;
char    **array;
int i = 1;
int data;

if(argc < 2)
        return (0);
// long number = ft_atoi(argv[i]);
// if (number < INT_MIN || number > INT_MAX)
// {
//     write(2, "Error\n", 5);
//     return(0);
// }
if(!good_input(&argv[i]))
{
    write(2, "Error\n", 5);
    return(0);
}
if(not_duplicate(argv))
{
    write(2, "Error\n", 5);
    return(0);
}

if (argc == 2)
{
    int j = 0; 
    array = ft_split(argv[i], ' ');
    if (!array)
    {
        write(2, "Error\n", 6);
        exit(1);
    }
    while (array[j])
    {
        data = ft_atoi(array[j]);
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
    long number = ft_atoi(argv[i]);
    if (number < INT_MIN || number > INT_MAX)
    {
        write(2, "Error\n", 5);
        return(0);
    }
}
if (argc > 2)
{
    int j = 1; 
    while (j < argc)
    {
        data = ft_atoi(argv[j]);
        append_node(&stack_a, data);
        j++;
    }
    long number = ft_atoi(argv[i]);
    if (number < INT_MIN || number > INT_MAX)
    {
        write(2, "Error\n", 5);
        return(0);
    }
assign_ranks(&stack_a);
}
if (argc == 6)
    five_sort(&stack_a, &stack_b);
if (argc == 5)
    four_sorting(&stack_a, &stack_b);
if (argc == 4 || argc == 3)
    three_sorting(&stack_a);
else if (argc > 6)
{
    sort(&stack_a, &stack_b);
    push_back_to_a(&stack_a, &stack_b);
}
/////Coment this!!!!!!!!!!!!!!!!!!!!!!
printf("//////////////////////Stack_b////////////////////////\n");
print_data(stack_b);
printf("/////////////////////////Stack_a////////////////////////\n");
print_data(stack_a);

return(0);
}