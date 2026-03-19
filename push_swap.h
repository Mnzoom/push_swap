/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:45:33 by cn-goie           #+#    #+#             */
/*   Updated: 2025/12/17 03:48:43 by cn-goie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

typedef struct s_node
{
    int value;
    int index;
    struct s_node   *next;
    struct s_node   *prev;
}   t_node;

static void exit_error(char **split);
static int  is_number(char *str);
static int  ft_atoi_safe(char *str);
static int is_duplicate(t_node *stack, int value);
void    parse_and_fill_stack(int ac, char **av, t_node **stack_a);


void    sb(t_node **stack_b);
void    sa(t_node **stack_a);

t_node *create_node(int value);
void add_node_bottom(t_node **stack, t_node *new);
void add_node_top(t_node **stack, t_node *new);
t_node *stack_last(t_node *stack);
int stack_size(t_node *stack);
t_node *stack_min(t_node *stack);
void free_stack(t_node **stack);

