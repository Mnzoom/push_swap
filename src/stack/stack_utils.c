/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:36:26 by cn-goie           #+#    #+#             */
/*   Updated: 2025/12/16 18:36:57 by cn-goie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_node *stack_min(t_node *stack)
{
    t_node *min;

    if (!stack)
        return (NULL);
    min = stack;
    while (stack)
    {
        if (stack->value < min->value)
            min = stack;
        stack = stack->next;
    }
    return min;
}

void free_stack(t_node **stack)
{
    t_node *tmp;

    while (stack && *stack)
    {
        tmp = (*stack)->next;
        free(*stack);
        *stack = tmp;
    }
}
