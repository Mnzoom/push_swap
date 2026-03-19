/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clementngoie <clementngoie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:31:33 by clementngoi       #+#    #+#             */
/*   Updated: 2026/03/19 13:31:43 by clementngoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_node **stack_a, t_node **stack_b)
{
	t_node	*prev;
	t_node	*last;
	if (stack_a && *stack_a && (*stack_a)->next)
	{
		last = *stack_a;
		while (last->next)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = *stack_a;
		*stack_a = last;
	}
	if (stack_b && *stack_b && (*stack_b)->next)
	{
		last = *stack_b;
		while (last->next)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = *stack_b;
		*stack_b = last;
	}
	write(1, "rrr\n", 4);
}