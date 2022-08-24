/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:21:56 by ghahn             #+#    #+#             */
/*   Updated: 2022/08/24 15:50:33 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(va_list lst, char x)
{
	char	*s;
	char	t;

	if (x == 's')
	{
		s = va_arg(lst, char *);
		if (s == NULL)
			return (NULL);
		write(1, s, ft_strlen(s));
		return (ft_strlen(s));
	}
	else
	{
		t = va_arg(lst, int);
		write(1, &t, 1);
		return (1);
	}
}
