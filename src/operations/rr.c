/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:27:53 by clementngoi       #+#    #+#             */
/*   Updated: 2026/04/29 16:16:52 by cn-goie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_node **stack_a, t_node **stack_b)
{
	t_node	*first;
	t_node	*last;

	if (stack_a && *stack_a && (*stack_a)->next)
	{
		first = *stack_a;
		last = *stack_a;
		while (last->next)
			last = last->next;
		*stack_a = first->next;
		first->next = NULL;
		last->next = first;
	}
	if (stack_b && *stack_b && (*stack_b)->next)
	{
		first = *stack_b;
		last = *stack_b;
		while (last->next)
			last = last->next;
		*stack_b = first->next;
		first->next = NULL;
		last->next = first;
	}
	write(1, "rr\n", 3);
}
