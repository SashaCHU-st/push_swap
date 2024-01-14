/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:50:55 by aheinane          #+#    #+#             */
/*   Updated: 2024/01/14 11:35:37 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct node {
	int			data;
	int			rank;
	
	struct node	*link;
}t_node;

int		ft_atoi(const char *str);
void	append_node(struct node **head, int data);
void	assign_ranks(struct node **stack);
void	print_data(struct node *head);
void	sorting(struct node **head);
int		ft_lstsize(struct node *lst);
void	push(int data, struct node **stack);
void	from_last_to_first(struct node **stack);
void	from_first_to_last(struct node **stack);
void	rrr(struct node **stack_a, struct node **stack_b);
void	rr(struct node **stack_a, struct node **stack_b);
void	ss(struct node **stack_a, struct node **stack_b);
void	sa(struct node **stack_a);
void	sb(struct node **stack_b);
void	rra(struct node **stack);
void	rrb(struct node **stack);
void	ra(struct node **stack);
void	rb(struct node **stack);
void	pa(int data, struct node **stack);
void	pb(int data, struct node **stack);
int		pop(struct node **stack);
void	three_sorting(struct node **stack_a);
void	five_sort(struct node **stack_a, struct node **stack_b);
void	four_sorting(struct node **stack_a, struct node **stack_b);
void	two_sorting(struct node **stack);
void	three_sorting_case(struct node **stack);
void	three_sorting(struct node **stack);
void	sort(struct node **stack_a, struct node **stack_b);
void	push_back_to_a(struct node **stack_a, struct node **stack_b);


#endif