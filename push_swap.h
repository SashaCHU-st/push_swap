/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:50:55 by aheinane          #+#    #+#             */
/*   Updated: 2024/02/10 17:47:33 by aheinane         ###   ########.fr       */
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
	struct node		*link;
}t_node;

struct ProcessParams {
    unsigned int *count;
    unsigned int *groups;
    unsigned int *remainder;
    unsigned int *i;
};
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
void	push_back_to_a(struct node **stack_a, struct node **stack_b);
int		position(struct node *stack, unsigned int target);
int		closest_number_in(struct node *stack_a, unsigned int target);
int		last_node(struct node* stack);
int		duplicated(struct node *stack, int n);
char	*free_function(char **str);
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
void	adjust_stack_a(struct node **stack_a);

void sort_100(struct node **stack_a, struct node **stack_b);
void sort_500(struct node **stack_a, struct node **stack_b);


void process_arguments(int argc, char **argv, struct node **stack_a, struct node **stack_b);
void process_arguments_with_split(char **argv, struct node **stack_a, struct node **stack_b);
void process_arguments_without_split(int argc, char **argv, struct node **stack_a, struct node **stack_b);


void push_elements_to_stack_b_n(struct node **stack_a, struct node **stack_b, unsigned int num_groups, unsigned int size_a);
void sort(struct node **stack_a, struct node **stack_b,size_t size_a, size_t group_size);
void process_nodes(struct node **stack_a, struct node **stack_b, unsigned int *count, unsigned int groups, unsigned int i, unsigned int remainder);
void rotate_to_top(struct node **stack_a, struct node **stack_b, int position);
int find_closest_number(struct node **stack_a, int rank_b);
int calculate_position(struct node **stack_a, int closest_number);
void push_less_than_three_to_stack_b(struct node **stack_a, struct node **stack_b, int *size);
void rotate_stack_a_greater_than_two(struct node **stack_a);
void sort_within_group(struct node **stack_a, struct node **stack_b, unsigned int group_size);
#endif