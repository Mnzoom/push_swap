/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clementngoie <clementngoie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 03:49:12 by cn-goie           #+#    #+#             */
/*   Updated: 2026/03/19 14:13:02 by clementngoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ss(t_node **stack)
{
    t_node  *first;
    t_node  *second;
    if (!stack || !*stack || !(*stack)->next)
        return;
    first = *stack;
    second = first->next;

    first->next = second->next;
    if (second->next)
        second->next->prev = first;
    second->prev = NULL;
    second->next = first;
    first->prev = second;
    *stack = second;
    write(1, "ss\n", 3);
}