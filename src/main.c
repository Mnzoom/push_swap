/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:51:14 by cn-goie           #+#    #+#             */
/*   Updated: 2025/12/16 18:40:00 by cn-goie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int ac, char **av)
{
    t_node *stack_a = NULL;
    int i;

    if (ac < 2)
        return 0;

    parse_and_fill_stack(ac, av, &stack_a);
    t_node *tmp = stack_a;
    while (tmp)
    {
        printf("value: %d\n", tmp->value);
        tmp = tmp->next;
    }

    free_stack(&stack_a);
    return 0;
}