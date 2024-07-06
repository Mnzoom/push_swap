/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:20:34 by marvin            #+#    #+#             */
/*   Updated: 2024/07/05 20:20:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int syn_error(char *str_n) //on def une fonction pour les erreurs de syntaxe
{
    if(!(*str_n == '+' || *str_n == '-' || (*str_n == >= '0' && str_n <= '9'))) //On regarde le premier character si c'est in signe ou un chiffre
        return (1);
    if ((*str_n == '+' ||*str_n == '-') && !(str_n[1] >= '0' && str_n[1] <= '9')) // Apres on verifie si le premier ch est un signe qui n'est pas suivie d'un chiffre 
        return (1);
    while(*++str_n) // si les conditions sont passée on loop jusqu'au ch suivant
    {
        if(!(*str_n >= '0' && *str_n <= '9'))
            return (1);
    }
    return (0); // On aura return 1 si jamais les conditions d'erreurs sont trouvés
}

int error_duplicate(t_stack_node a*, int n)
{
    if(!a) //Check si stack vide 
        return (0);
    while (a) //Loop jusque la fin de la stack pour checker si doublons il y a 
    {
        if (a->nbr == n)
            return (1);
        a = a->next;
    }
    return (0);
}

void    free_stack(t_stack_node stack**) //Si erreur fonction qui free la stack
{
    t_stack_node    *tmp; // On garde notre prochain chainons avant de free le chainos actuel pour ne rien perdre 
    t_stack_node    *current;

    if (!stack) // Check stack vide
        return ;
    current = *stack;
    while(current)
    {
        tmp = current->next; // Ici in stack la node suivante
        current->nbr = 0; //  Du bug prevention
        free(current);
        current = tmp; // Apres le free de current on donne la valeur de tmp a current 
    }
    *stack = NULL;
}

void    free_errors (t_stack_node a**)
{
    free_stack(a);
    ft_printf("Error\n");
    exit(1);
}