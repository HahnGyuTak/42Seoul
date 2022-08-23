/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:21:56 by ghahn             #+#    #+#             */
/*   Updated: 2022/08/23 15:29:14 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t  ft_strlen(char *s)
{
    size_t  i;
    
    i = 0;
    while (*s++)
        i++;
    return (i);
} 

int print_string(va_list lst, char x)
{
    char    *s;
    
    if (x == 's')
    {
        s = va_arg(lst, char*);
        write(1, s, ft_strlen(s));
        return (ft_strlen(s));
    }
    else
    {
        s = malloc(sizeof(char) * 2);
        s[0] = va_arg(lst, char);
        s[1] = '\0';
        write(1, s, 1);
        free(s);
        return (1);
    }
}