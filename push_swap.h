/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:50:55 by aheinane          #+#    #+#             */
/*   Updated: 2024/02/11 11:55:13 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct node
{
	int				data;
	unsigned int	rank;
	struct node		*link;
}				t_node;

/// init stack
void	append_node(t_node **stack, int data);
void	assign_ranks(t_node **stack);
int		closest_number_in(t_node *stack_a, unsigned int target);
int		last_node(t_node *stack);
int		position(t_node *stack, unsigned int target);

///split
int		ft_words(const char *str, char c);
char	*ft_wd(const char *str, char c);
void	free_w(size_t i, char **ptr);
char	**ft_split(char const *s, char c);

///process arguments
void	sorting(int argc, char **argv, t_node **stack_a, t_node **stack_b);
void	arg_split(char **argv, t_node **stack_a, t_node **stack_b);
void	arg_no_split(int argc, char **argv, t_node **stack_a, t_node **stack_b);

///input checker
int		duplicated(t_node *stack, int n);
int		is_sign(char c);
int		not_good_input(char *str);

//push_swap_utils
long	ft_atoi(const char *str);
int		ft_lstsize(t_node *lst);
int		is_sorted(t_node *stack);
char	*free_function(char **str);///?????
int		error(void);

//push
void	push(int rank, t_node **stack);
int		pop(t_node **stack);
void	pa(int rank, t_node **stack);
void	pb(int rank, t_node **stack);

///swap
void	swap(t_node **stack);
void	sa(t_node **stack);
void	sb(t_node **stack);
void	ss(t_node **stack_a, t_node **stack_b);

///reverse frirst
void	from_first_to_last(t_node **stack);
void	ra(t_node **stack);
void	rb(t_node **stack);
void	rr(t_node **stack_a, t_node **stack_b);

//reverse from last
void	from_last_to_first(t_node **stack);
void	rra(t_node **stack);
void	rrb(t_node **stack);
void	rrr(t_node **stack_a, t_node **stack_b);

///soort
void	sort(t_node **stack_a, t_node **stack_b, size_t size_a, size_t group);
void	sort_100(t_node **stack_a, t_node **stack_b);
void	sort_500(t_node **stack_a, t_node **stack_b);

//sorting algo
void	rotate_to_top(t_node **stack_a, t_node **stack_b, int position);
int		find_closest_number(t_node **stack_a, int rank_b);
int		calculate_position(t_node **stack_a, int closest_number);
void	push_back_to_a(t_node **stack_a, t_node **stack_b);

//r=three soruting
void	two_sorting(t_node **stack);
void	three_sorting_case(t_node **stack);
void	three_sorting(t_node **stack);
void	five_sort(t_node **stack_a, t_node **stack_b);
void	four_sorting(t_node **stack_a, t_node **stack_b);

//helping function
void	push_less_than_three_tob(t_node **stack_a, t_node **stack_b, int *size);
void	rotate_stack_a_greater_than_two(t_node **stack_a);
void	process_stack(t_node **stack_a, t_node **stack_b, int size);
void	process_argument(t_node **stack_a, char *arg);
void	adjust_stack_a(t_node **stack_a);

//free_stack
void	free_stack(t_node **stack);

#endif