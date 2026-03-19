/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clementngoie <clementngoie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:43:34 by clementngoi       #+#    #+#             */
/*   Updated: 2026/03/19 13:45:25 by clementngoi      ###   ########.fr       */
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