/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:51:17 by cn-goie           #+#    #+#             */
/*   Updated: 2026/04/29 16:29:07 by cn-goie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	process_split_elements(char **split, t_node **stack_a)
{
	int		j;
	long	val;

	j = 0;
	while (split[j])
	{
		if (!is_number(split[j]))
			exit_error(stack_a, split);
		val = ft_atol(split[j]);
		if (val > INT_MAX || val < INT_MIN)
			exit_error(stack_a, split);
		if (is_duplicate(*stack_a, (int)val))
			exit_error(stack_a, split);
		add_node_bottom(stack_a, create_node((int)val));
		j++;
	}
	ft_free_split(split);
}

void	parse_and_fill_stack(int ac, char **av, t_node **stack_a)
{
	int		i;
	char	**split;

	i = 1;
	while (i < ac)
	{
		split = ft_split(av[i], ' ');
		if (!split)
			exit_error(stack_a, NULL);
		if (av[i][0] == '\0' || split[0] == NULL)
		{
			ft_free_split(split);
			exit_error(stack_a, NULL);
		}
		process_split_elements(split, stack_a);
		i++;
	}
}
