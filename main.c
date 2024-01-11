/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:29:05 by aheinane          #+#    #+#             */
/*   Updated: 2024/01/11 13:17:20 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

int main(int argc, char *argv[])
{
//struct node *temp;
struct node *stack_a = NULL;
struct node *stack_b = NULL;
int i = 1;
int data;
//int temp;
int size = 1;
/// if argc = 3 togda ando simple function
    while (i < argc)
	{
        data = ft_atoi(argv[i]); 
        append_node(&stack_a, data);
        i++;
    }
assign_ranks(&stack_a);
size = ft_lstsize(stack_a);

printf("\nSIZE:%d\n",size);
//int tail=get_nth(stack_a, size);

printf("/////////////////////////Original:////////////////////////\n");
printf("Stack_a \n");
print_data(stack_a);

//printf("\n");

/////////////////////////////////////////
// stack_a = push_b(data, stack_a);
// temp= pop_a(stack_a);
// stack_a= temp->link;


// stack_b= push_b(temp->data, stack_b);
// temp= pop_a(stack_a);
// stack_a= temp->link;
// stack_b= push_b(temp->data, stack_b);
///////////////////////////////////////////
//push_b(data, &stack_a);

/////////////// POP_A FROM STACK_A AND PUSH TO STACK_B  1. 
printf("////////////////////////Comands////////////////////////\n");
if (size == 5)
    five_sort(&stack_a, &stack_b);
if (size == 4)
    four_sorting(&stack_a, &stack_b);
if (size == 3)
    three_sorting(&stack_a);



/////sorting for 4


// else if (size == 2)
//     two_sorting(&stack_a);


// while (size > 0)
// {
//     if(stack_a->rank == 2 && stack_a->link->rank == 1 )
//     {
//         temp= pop(&stack_b);
//         pa(temp, &stack_a);
//         size--; 
//     }
//     else
//     {
//         sb(&stack_b);
//         temp= pop(&stack_b);
//         pa(temp, &stack_a);
//         size--; 
//     }
// }


printf("//////////////////////Stack_b////////////////////////\n");
print_data(stack_b);


printf("/////////////////////////Stack_a////////////////////////\n");
print_data(stack_a);

// //////ONE MORE TIME 2. 
// temp= pop(&stack_a);
// pb(temp, &stack_b);

// //////ONE MORE TIME 3. 
// temp= pop(&stack_a);
// pb(temp, &stack_b);

// //////ONE MORE TIME 4.
// temp= pop(&stack_a);
// pb(temp, &stack_b);

// ////////PUSH BACK FROM STACK_B. POP FROM B AND PUSH TO B
// temp= pop(&stack_b);
// pa(temp, &stack_a);


// printf("//////////////////////Stack_b////////////////////////\n");
// print_data(stack_b);


// printf("/////////////////////////Stack_a////////////////////////\n");
// print_data(stack_a);

// printf("///////Reverse Comands from last to front///////////////\n");
// rra(&stack_a);
// rrb(&stack_b);

// printf("///////Stack_a after last became fist node//////////////\n");
// print_data(stack_a);

// printf("///////Stack_b after last became fist node//////////////\n");
// print_data(stack_b);

// printf("///////Reverse Comands from front to last///////////////\n");
// ra(&stack_a);
// rb(&stack_b);

// printf("///////Stack_a after first became last node/////////////\n");
// print_data(stack_a);

// printf("///////Stack_b after first became last node/////////////\n");
// print_data(stack_b);

// printf("///////swaping stack_a and  stack_b/////////////////////\n");
// sa(&stack_a);
// sb(&stack_b);

// printf("///////swaping stack_a///////////////////////////////////\n");
// print_data(stack_a);
// printf("///////swaping stack_b///////////////////////////////////\n");
// print_data(stack_b);

// printf("///////reversing at the same time both///////////////////\n");
// rr(&stack_a,&stack_b);
// printf("///////moving from first to last stack_a/////////////////\n");
// print_data(stack_a);
// printf("//////moving from first to last stack_b/////////////////\n");
// print_data(stack_b);

// printf("//////reversing at the same time both///////////////////\n");
// rrr(&stack_a,&stack_b);
// printf("/////moving from last to first stack_a//////////////////\n");
// print_data(stack_a);
// printf("////moving from last to first stack_b///////////////////\n");
// print_data(stack_b);

// printf("///Swaping at the same time both////////////////////////\n");
// ss(&stack_a,&stack_b);
// printf("///swaping stack_a//////////////////////////////////////\n");
// print_data(stack_a);
// printf("////////////swaping stack_b//////////////////////////////\n");
// print_data(stack_b);


return(0);
}