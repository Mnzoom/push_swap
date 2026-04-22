/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clementngoie <clementngoie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:51:17 by cn-goie           #+#    #+#             */
/*   Updated: 2026/03/20 14:06:52 by clementngoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    parse_and_fill_stack(int ac, char **av, t_node **stack_a)
{
    int     i = 1;
    int     j;
    long    val;
    char    **split;

    while (i < ac)
    {
        split = ft_split(av[i], ' ');
        if (!split) 
            exit_error(stack_a, NULL);
        if (av[i][0] == '\0' || split[0] == NULL)
        {
            ft_free_split(split);
            exit_error(stack_a, NULL);
        }
        j = 0;
        while (split[j])
        {
            if (!is_number(split[j])) exit_error(stack_a, split);
            val = ft_atol(split[j]);
            if (val > INT_MAX || val < INT_MIN) exit_error(stack_a, split);
            if (is_duplicate(*stack_a, (int)val)) exit_error(stack_a, split);
            
            add_node_bottom(stack_a, create_node((int)val));
            j++;
        }
        ft_free_split(split);
        i++;
    }
}