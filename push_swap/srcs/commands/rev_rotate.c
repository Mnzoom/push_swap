/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngoie <mngoie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:40:58 by mngoie            #+#    #+#             */
/*   Updated: 2024/10/23 13:41:16 by mngoie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"


static void	rev_rotate(t_stack_node **stack)
{
    t_stack_node	*last;

    if (!*stack || !(*stack)->next)
        return ;
    last = find_last(*stack);
    last->prev->next = NULL;
    last->next = *stack;
    last->prev = NULL;
    *stack = last;
    last->next->prev = last;
}

void	rra(t_stack_node **a, bool print)
{
    rev_rotate(a);
    if (!print)
        ft_printf("rra\n");
}

void	rrb(t_stack_node **b, bool print)
{
    rev_rotate(b);
    if (!print)
        ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b, bool print)
{
    rev_rotate(a);
    rev_rotate(b);
    if (!print)
        ft_printf("rrr\n");
}
