/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:31:41 by marvin            #+#    #+#             */
/*   Updated: 2024/08/03 13:31:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void    sort_three(t_stack_node a**) /*fonction qui handle 3 nodes dans stack a et les sorts*/
{
    t_stack_node    *biggest_node; /* store un pointeur dans la biggest node dans 'a'*/

    biggest_node = find_max(*a);
    if (biggest_node == *a) /*verification si la node en cours et la plus grande*/
        ra(a, false); /* si oui rotate the top node en bas de la stack*/
    else if ((*a)->next == biggest_node) /*check la deuxieme*/
        rra(a, false); /*si oui reverse rotate la node du bas en haut de la stack*/
    if ((*a)->nbr > (*a)->next->nbr)
        sa(a, false); /* si la node du bas est la plus grande on swap juste les deux autres*/
}