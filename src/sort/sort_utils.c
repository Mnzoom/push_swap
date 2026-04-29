/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:43:34 by clementngoi       #+#    #+#             */
/*   Updated: 2026/04/29 16:40:21 by cn-goie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_node *stack_a)
{
	t_node	*current;
	t_node	*compare;
	int		index;

	current = stack_a;
	while (current)
	{
		index = 0;
		compare = stack_a;
		while (compare)
		{
			if (current->value > compare->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

int	is_sorted(t_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	get_distance(t_node *stack, int index)
{
	int	distance;

	distance = 0;
	while (stack)
	{
		if (stack->index == index)
			return (distance);
		distance++;
		stack = stack->next;
	}
	return (distance);
}

int	get_target_pos(t_node **stack, int target_index)
{
	t_node	*tmp;
	int		pos;

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
