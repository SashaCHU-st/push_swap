/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:50:55 by aheinane          #+#    #+#             */
/*   Updated: 2024/02/08 17:36:04 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct node {
	int				data;
	unsigned int	rank;
	unsigned int	cost_a;
	unsigned int	cost_b;
	struct node		*link;
}t_node;

long	ft_atoi(const char *str);
void	append_node(struct node **head, int data);
void	assign_ranks(struct node **stack);
void	print_data(struct node *head);
int		ft_lstsize(struct node *lst);
void	push(int data, struct node **stack_dest);
int		pop(struct node **stack);
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
void	three_sorting(struct node **stack_a);
void	five_sort(struct node **stack_a, struct node **stack_b);
void	four_sorting(struct node **stack_a, struct node **stack_b);
void	two_sorting(struct node **stack);
void	three_sorting_case(struct node **stack);
void	three_sorting(struct node **stack);
void	sort(struct node **stack_a, struct node **stack_b);
void	push_back_to_a(struct node **stack_a, struct node **stack_b);
int		position(struct node *stack, unsigned int target);
int		closest_number_in(struct node *stack_a, unsigned int target);
int		last_node(struct node* stack);
void	sort(struct node **stack_a, struct node **stack_b);
void	cost(struct node **stack_a,struct node **stack_b);
int		duplicated(struct node *stack, int n);
char	*free_function(char **str);
int		cmp(char *str1, char *str2);
int		ft_words(const char *str, char c);
char	*ft_wd(const char *str, char c);
void	free_w(size_t i, char **ptr);
char	**ft_split(char const *s, char c);
int		zeros(char *argv);
int		not_good_input(char *str);
int		is_sorted(struct node *stack);
int		error();
void	process_stack(struct node **stack_a, struct node **stack_b, int size);
void	process_argument(struct node **stack_a, char *arg);

void sort(struct node **stack_a, struct node **stack_b);
void divide_stack_into_groups(struct node **stack_a, struct node **stack_b, unsigned int size_a, unsigned int groups, unsigned int remainder);
void push_elements_to_stack_b(struct node **stack_a, struct node **stack_b, unsigned int groups) ;
void rotate_stack_a_after_push(struct node **stack_a,struct node **stack_b, unsigned int size_a, unsigned int groups, unsigned int remainder);

void push_elements_to_stack_b(struct node **stack_a, struct node **stack_b, unsigned int groups);
void push_elements_to_stack_b_2(struct node **stack_a, struct node **stack_b, unsigned int groups, unsigned int remainder);
void push_elements_to_stack_b_3(struct node **stack_a, struct node **stack_b, unsigned int groups, unsigned int remainder);

void process_arguments(int argc, char **argv, struct node **stack_a, struct node **stack_b);
void process_arguments_with_split(char **argv, struct node **stack_a, struct node **stack_b);
void process_arguments_without_split(int argc, char **argv, struct node **stack_a, struct node **stack_b);

#endif