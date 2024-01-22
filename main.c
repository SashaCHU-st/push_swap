/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:29:05 by aheinane          #+#    #+#             */
/*   Updated: 2024/01/22 17:00:32 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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
// if(good_input(argv))
// {
//     write(1, "Error1\n", 6);
//     return(0);
// }
// if(!&not_duplicate)
// {
//     write(1, "Error2\n", 6);
//     return(0);
// }
if (argc == 2 )
{
   int j = 1; 
    array = ft_split(argv[i], ' ');
    if (!array)
    {
        write(2, "Error1\n", 6);
        exit(1);
    }
    while (array[j])
    {
        data = ft_atoi(array[j]);
        append_node(&stack_a, data);
        j++;
    }
    free(array);
}

int j = 1; 
while (j < argc)
{
    data = ft_atoi(argv[j]);
        append_node(&stack_a, data);
        j++;
}

assign_ranks(&stack_a);
if (j == 6)
{
    five_sort(&stack_a, &stack_b);
    //printf("helo");
}
if (j == 5)
    four_sorting(&stack_a, &stack_b);
if (j == 4 || j == 3)
    three_sorting(&stack_a);
else if (j > 6)
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