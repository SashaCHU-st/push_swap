/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:50:55 by aheinane          #+#    #+#             */
/*   Updated: 2024/01/06 12:22:42 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct node {
	int data;
	struct node *link;
}t_node;



int	ft_atoi(const char *str);
void appendNode(struct node **head, int data);
void push_b(int data, struct node** stack_b);
void print_data(struct node *head);
int pop_a(struct node** stack_b);
void push_a(int data, struct node** stack_a);
int pop_b(struct node** stack_a);
void from_last_to_first_a(struct node **stack_a);
void from_last_to_first_b(struct node **stack_b);


#endif