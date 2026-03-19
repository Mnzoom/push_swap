/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clementngoie <clementngoie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:51:14 by cn-goie           #+#    #+#             */
/*   Updated: 2026/03/19 14:28:35 by clementngoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_all(t_node **stack_a, t_node **stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
}

void	print_stacks(t_node *a, t_node *b)
{
	printf("\n--- STACK A ---    --- STACK B ---\n");
	while (a || b)
	{
		if (a)
		{
			printf("  %d", a->value);
			a = a->next;
		}
		else
			printf("   ");
		printf("                ");
		if (b)
		{
			printf("%d", b->value);
			b = b->next;
		}
		printf("\n");
	}
	printf("----------------------------------\n\n");
}

int main(int ac, char **av)
{
    t_node  *stack_a;
    t_node  *stack_b;
    int     size;

    if (ac < 2)
        return (0);
    stack_a = NULL;
    stack_b = NULL;
    parse_and_fill_stack(ac, av, &stack_a);
    if (is_sorted(stack_a))
    {
        free_stack(&stack_a);
        return (0);
    }
    set_index(stack_a);
    size = stack_size(stack_a);
    if (size == 2)
        sa(&stack_a);
    else if (size == 3)
        sort_three(&stack_a);
    else if (size <= 5)
        sort_five(&stack_a, &stack_b); 
    else
        big_sort(&stack_a, &stack_b);
     print_stacks(stack_a, stack_b);
    free_all(&stack_a, &stack_b);
    return (0);
}