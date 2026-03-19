/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clementngoie <clementngoie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:47:55 by clementngoi       #+#    #+#             */
/*   Updated: 2026/03/19 16:34:58 by clementngoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_target_pos(t_node **stack, int target_index)
{
    t_node  *tmp;
    int     pos;

    pos = 0;
    tmp = *stack;
    while (tmp)
    {
        if (tmp->index == target_index)
            return (pos);
        tmp = tmp->next;
        pos++;
    }
    return (0);
}

void    push_back_to_a(t_node **stack_a, t_node **stack_b)
{
    int size;
    int max_pos;

    while (*stack_b)
    {
        size = stack_size(*stack_b);
        max_pos = get_target_pos(stack_b, size - 1);
        
        if (max_pos <= size / 2)
            while (max_pos-- > 0)
                rb(stack_b);
        else
        {
            max_pos = size - max_pos;
            while (max_pos-- > 0)
                rrb(stack_b);
        }
        pa(stack_a, stack_b);
    }
}

void    big_sort(t_node **stack_a, t_node **stack_b)
{
    int i;
    int range;
    int size;

    i = 0;
    size = stack_size(*stack_a);
    if (size <= 100) range = 15;
    else range = 35;

    while (*stack_a)
    {
        if ((*stack_a)->index <= i)
        {
            pb(stack_a, stack_b);
            rb(stack_b);
            i++;
        }
        else if ((*stack_a)->index <= i + range)
        {
            pb(stack_a, stack_b);
            i++;
        }
        else
            ra(stack_a);
    }
    push_back_to_a(stack_a, stack_b);
}