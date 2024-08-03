/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:11:55 by marvin            #+#    #+#             */
/*   Updated: 2024/01/07 15:11:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#   define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include // put ft_printf//
# include // put libft // 

typedef struct s_stack_node //A container of data enclosed in {} braces. `s_` for struct
{
	int					nbr;
	int					index; 
	int					push_cost; 
	bool				above_median; 
	bool				cheapest; 
	struct s_stack_node	*target_node; 
	struct s_stack_node	*next; 
	struct s_stack_node	*prev; 
}	t_stack_node; 


/*Handle errors*/
int	error_syntax(char *str_n);
int	error_duplicate(t_stack_node *a, int n);
void	free_stack(t_stack_node **stack);
void	free_errors(t_stack_node **a);

/*Stack initiation*/
void	init_stack_a(t_stack_node a**, char **av);ù
char	**split(char *s, char c);

/*Nodes initiation*/
void	init_nodes_a(t_stack_node *a, t_stack_node *b);
void	init_nodes_b(t_stack_node *a, t_stack_node *b);
void	current_index(t_stack_node *stack);
void	set_cheapest(t_stack_node *stack);
t_stack_node	*get_cheapest(t_stack_node *stack);
void	prep_for_push(t_stack_node **s, t_stack_node *n, char c);

/* STACK UTILS*/
int	stack_len(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack);
bool	stack_sorted(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);

/* INSTRUCTION */
void sa(t_stack_node **a, bool print);
void sb(t_stack_node **b, bool print);
void ss(t_stack_node **a, t_stack_node **b, bool print);
void pa(t_stack_node **a,bool print);
void pb(t_stack_node **b,bool print);
void ra(t_stack_node **a, t_stack_node **b, bool print);
void rb(t_stack_node **a, bool print);
void rr(t_stack_node **b,bool print);
void rra(t_stack_node **a,t_stack_node **b, bool print);
void rrb(t_stack_node **a,t_stack_node **b, bool print);
void rrr(t_stack_node **b,t_stack_node **a, bool print);

/*MOVES*/
void	pa(t_stack_node **a, t_stack_node **b, bool print);
void	pb(t_stack_node **b, t_stack_node **a, bool print);

/* ALGOTITHM  */
void    sort_three(t_stack_node **a);
void    sort_stack(t_stack_node **a, t_stack_node **b);

#endif