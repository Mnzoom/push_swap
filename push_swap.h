/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clementngoie <clementngoie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:45:33 by cn-goie           #+#    #+#             */
/*   Updated: 2026/03/19 16:33:40 by clementngoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"
#include <limits.h>

typedef struct s_node
{
    int value;
    int index;
    struct s_node   *next;
    struct s_node   *prev;
}   t_node;

void exit_error(t_node **stack,char **split);
int  is_number(char *str);
int is_duplicate(t_node *stack, int value);
void    parse_and_fill_stack(int ac, char **av, t_node **stack_a);
long	ft_atol(const char *str);
void ft_free_split(char **split);


void    sb(t_node **stack_b);
void    sa(t_node **stack_a);
void    ss(t_node **stack);
void	pb(t_node **stack_a, t_node **stack_b);
void	pa(t_node **stack_a, t_node **stack_b);
void	rb(t_node **stack_b);
void	ra(t_node **stack_a);
void	rr(t_node **stack_a, t_node **stack_b);
void	rrb(t_node **stack_b);
void	rra(t_node **stack_a);
void	rrr(t_node **stack_a, t_node **stack_b);


t_node *create_node(int value);
void add_node_bottom(t_node **stack, t_node *new);
void add_node_top(t_node **stack, t_node *new);
t_node *stack_last(t_node *stack);
int stack_size(t_node *stack);
t_node *stack_min(t_node *stack);
void free_stack(t_node **stack);
int get_target_pos(t_node **stack, int target_index);
void	set_index(t_node *stack_a);
int	is_sorted(t_node *stack);
int	get_distance(t_node *stack, int index);
void	sort_three(t_node **stack_a);
void    sort_five(t_node **stack_a, t_node **stack_b); 

void    push_back_to_a(t_node **stack_a, t_node **stack_b);
void	big_sort(t_node **stack_a, t_node **stack_b);

#endif