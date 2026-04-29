/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k-sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:47:55 by clementngoi       #+#    #+#             */
/*   Updated: 2026/04/29 16:38:47 by cn-goie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_and_check(t_node **a, t_node **b, int target, int dir)
{
	int	pos;

	pos = get_target_pos(b, target);
	if (dir == 0)
		pos = stack_size(*b) - pos;
	while (pos-- > 0)
	{
		if ((*b)->index == target - 1)
			pa(a, b);
		else if (dir == 1)
			rb(b);
		else
			rrb(b);
	}
}

static void	prepare_push_b(t_node **stack_a, t_node **stack_b, int size)
{
	int	max_pos;

	max_pos = get_target_pos(stack_b, size - 1);
	if (max_pos <= size / 2)
		rotate_and_check(stack_a, stack_b, size - 1, 1);
	else
		rotate_and_check(stack_a, stack_b, size - 1, 0);
}

void	push_back_to_a(t_node **stack_a, t_node **stack_b)
{
	int	size;

	while (*stack_b)
	{
		size = stack_size(*stack_b);
		prepare_push_b(stack_a, stack_b, size);
		pa(stack_a, stack_b);
		if (stack_size(*stack_a) > 1
			&& (*stack_a)->index > (*stack_a)->next->index)
			sa(stack_a);
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
