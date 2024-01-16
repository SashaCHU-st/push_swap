/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:29:05 by aheinane          #+#    #+#             */
/*   Updated: 2024/01/16 16:56:06 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"

int main(int argc, char *argv[])
{
//struct node *temp;
struct node *stack_a = NULL;
struct node *stack_b = NULL;
int i = 1;
int data;
//int temp;
//int size = 1;


//write(1,"hello\n", 6);

fflush(stdout);

while (i < argc)
	{
        data = ft_atoi(argv[i]);
        append_node(&stack_a, data);
        i++;
    }
assign_ranks(&stack_a);
//size = ft_lstsize(stack_a);

// printf("/////////////////////////Original:////////////////////////\n");
// printf("Stack_a \n");
// print_data(stack_a);

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
//printf("////////////////////////Comands////////////////////////\n");
//printf("\nSIZE:%d\n",size);
if (argc == 6)
    five_sort(&stack_a, &stack_b);
if (argc == 5)
    four_sorting(&stack_a, &stack_b);
if (argc == 4 || argc == 3)
    three_sorting(&stack_a);
else if (argc > 6)
{
    sort(&stack_a, &stack_b);
   // position(&stack_b);
   //push_back_to_a(&stack_a, &stack_b);
    
}

///////Coment this!!!!!!!!!!!!!!!!!!!!!!
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