/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:16:30 by aheinane          #+#    #+#             */
/*   Updated: 2024/01/06 15:33:10 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

void    appendNode(struct node **head, int data)
{   
    struct node *last;
    struct node *newNode;
    
    last = *head;
    newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->link = NULL;
    if (*head == NULL)
    *head = newNode;
    else 
    {
        while (last->link != NULL) 
            last = last->link;
        last->link = newNode;
    }
}

void    print_data(struct node *head)
{ 
    struct node *ptr;
    if (head == NULL)
        printf("Empty");
    ptr = NULL;
    ptr = head;
    while(ptr)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->link;
    }
}