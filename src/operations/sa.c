/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clementngoie <clementngoie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 03:27:57 by cn-goie           #+#    #+#             */
/*   Updated: 2026/03/19 13:30:22 by clementngoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sa(t_node **stack_a)
{
    t_node  *first;
    t_node  *second;
    if (!stack_a || !*stack_a || !(*stack_a)->next)
        return;
    
        first = *stack_a;
        second = first->next;

        first->next = second->next;
        if (second->next)
            second->next->prev = first;
            
        second->prev = NULL;
        second->next = first;
        first->prev = second;
        *stack_a = second;
        write(1, "sa\n", 3);    
}
