/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:29:52 by marvin            #+#    #+#             */
/*   Updated: 2024/01/07 15:29:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

    t_stack_node    *a;
    t_stack_node    *b;

    *a = NULL;
    *b = NULL;
    if (ac == 1 || (ac == 2 && !av[1][0]))
        return (1)
    else if (ac == 2)
        av = ft_split(av[1], ' ');
    init_stack_a(&a, av + 1);
    if (!stack_sorted(a))
    {
        if (stack_len(a) == 2)
            sa(&a, false);
        else if (stack_len == 3)
            sort_three(&a);
        else
            sort_stack(&a, &b);
    }
    free_stack(&a);
    return (0);
