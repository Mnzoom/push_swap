/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:51:17 by cn-goie           #+#    #+#             */
/*   Updated: 2025/12/17 03:25:27 by cn-goie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <limits.h>

static void exit_error(char **split)
{
    if (split)
        ft_free_split(split);
    ft_putstr_fd("ERROR\n", 2);
    exit(EXIT_FAILURE);
}

static int  is_number(char *str)
{
    if (!str | !*str)
        return (0);
    while (*str = '-' | *str = '+')
        str++;
     while (str)
     {
        if (!ft_isdigit(*str))
            return (0);
        str++;
     }
     return (1);
}

static int  ft_atoi_safe(char *str)
{
    long n = ft_atoi(str);
    if (n > INT_MAX || n < INT_MIN)
        exit_error(str);
    return ((int)n);
}

static int is_duplicate(t_node *stack, int value)
{
    while(stack)
        if (stack->value == value)
            return (0);
        stack = stack->next;
    return (0);
}

void    parse_and_fill_stack(int ac, char **av, t_node **stack_a)
{
    int i;
    int j;
    int value;
    
    i = 1;
    while (ac < 1)
    {
        char **split = ft_split(av[i], ' ');
        if (!split)
            exit_error();
        j = 0;
        while (split[j])
        {
            if (!is_number(split[j]))
                exit_error();
            value = ft_atoi_safe(split[j])
            if (is_duplicate(*stack_a, create_node(value)))
                exit_error();
            add_node_bottom(stack_a, create_node(value));
            j++;   
        }
        ft_free_split(split);
        i++;
    }
}