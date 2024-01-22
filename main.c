/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:29:05 by aheinane          #+#    #+#             */
/*   Updated: 2024/01/22 11:32:39 by aheinane         ###   ########.fr       */
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
int i = 1;
int data;

// if(argc < 2)
//     return (0);
// if(!good_input(argv))
//     write(1, "Error\n", 6);
while (i < argc)
{
    data = ft_atoi(argv[i]);
    append_node(&stack_a, data);
    i++;
}
assign_ranks(&stack_a);
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
///////Coment this!!!!!!!!!!!!!!!!!!!!!!
printf("//////////////////////Stack_b////////////////////////\n");
print_data(stack_b);
printf("/////////////////////////Stack_a////////////////////////\n");
print_data(stack_a);

return(0);
}