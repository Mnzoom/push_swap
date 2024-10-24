/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngoie <mngoie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:04:20 by mngoie            #+#    #+#             */
/*   Updated: 2023/11/10 15:07:29 by mngoie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static  int ft_char_in_set(char c, char const *set)
{
    size_t  i;
    
    i = 0;
    while(set[i])
    {
        if (set[i] == c)
            return(1);
        i++;
    }
    return(0);
}
char    *ft_strtrim(const char *s1, const char *set)
{
    char *str;
    size_t i;
    size_t start;
    size_t end;
    
    start = 0;
    while (s1[start] && ft_char_in_set(s1[start], set))
        start++;
    end = ft_strlen(s1);
    while (end > start && ft_char_in_set(s1[end - 1], set))
        end--;
    str = (char *)malloc(sizeof(*s1) * (end - start + 1));
    if (!str)
        return (NULL);
    i = 0;
    while (start < end)
        str[i++] = s1[start++];
    str[i] = 0;
    return(str);
}