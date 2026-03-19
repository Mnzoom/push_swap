/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:51:20 by cn-goie           #+#    #+#             */
/*   Updated: 2025/12/16 18:36:05 by cn-goie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_node *create_node(int value)
{
    t_node *new = malloc(sizeof(t_node));
    if (!new)
        exit_error; 

    new->value = value;
    new->index = -1;  
    new->next = NULL;
    new->prev = NULL;

    return new;
}

void add_node_bottom(t_node **stack, t_node *new)
{
    t_node *last;

    if (!stack || !new)
        return;
    if (!*stack)
    {
        *stack = new;
        return;
    }
    last = *stack;
    while (last->next)
        last = last->next;
    last->next = new;
    new->prev = last;
}

void add_node_top(t_node **stack, t_node *new)
{
    if (!stack || !new)
        return;
    if (*stack)
        (*stack)->prev = new;
    new->next = *stack;
    new->prev = NULL;
    *stack = new;
}

t_node *stack_last(t_node *stack)
{
    if (!stack)
        return (NULL);
    while (stack->next)
        stack = stack->next;
    return (stack);
}

int stack_size(t_node *stack)
{
    int count = 0;
    while (stack)
    {
        count++;
        stack = stack->next;
    }
    return count;
}

