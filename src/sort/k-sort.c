/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k-sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:47:55 by clementngoi       #+#    #+#             */
/*   Updated: 2026/05/02 18:26:35 by cn-goie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_only(t_node **b, int pos, int dir, int b_size)
{
	if (dir == 0)
		pos = b_size - pos;
	while (pos-- > 0)
	{
		if (dir == 1)
			rb(b);
		else
			rrb(b);
	}
}

void	push_back_to_a(t_node **a, t_node **b)
{
	int	size;
	int	max_pos;

	while (*b)
	{
		size = stack_size(*b);
		max_pos = get_target_pos(b, size - 1);
		if (max_pos <= size / 2)
			rotate_only(b, max_pos, 1, size);
		else
			rotate_only(b, max_pos, 0, size);
		pa(a, b);
	}
}

static void	execute_big_sort(t_node **a, t_node **b, int range)
{
	int	i;

	i = 0;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else if ((*a)->index <= i + range)
		{
			pb(a, b);
			i++;
		}
		else
			ra(a);
	}
}

void	big_sort(t_node **stack_a, t_node **stack_b)
{
	int	size;
	int	range;

	size = stack_size(*stack_a);
	if (size <= 100)
		range = 15;
	else
		range = 35;
	execute_big_sort(stack_a, stack_b, range);
	push_back_to_a(stack_a, stack_b);
}
