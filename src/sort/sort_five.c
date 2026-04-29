/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 14:26:07 by clementngoi       #+#    #+#             */
/*   Updated: 2026/04/29 16:19:19 by cn-goie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	find_min_pos(t_node *stack)
{
	int		min_index;
	int		pos;
	int		min_pos;

	min_index = stack->index;
	pos = 0;
	min_pos = 0;
	while (stack)
	{
		if (stack->index < min_index)
		{
			min_index = stack->index;
			min_pos = pos;
		}
		pos++;
		stack = stack->next;
	}
	return (min_pos);
}

void	sort_five(t_node **stack_a, t_node **stack_b)
{
	int	pos;

	while (stack_size(*stack_a) > 3)
	{
		pos = find_min_pos(*stack_a);
		if (pos <= stack_size(*stack_a) / 2)
			while (pos--)
				ra(stack_a);
		else
		{
			pos = stack_size(*stack_a) - pos;
			while (pos--)
				rra(stack_a);
		}
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}
