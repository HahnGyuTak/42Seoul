/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:21:49 by ghahn             #+#    #+#             */
/*   Updated: 2022/08/24 15:38:21 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_integer(va_list lst, char x)
{
	long long	n;
	char		*s;

	if (x == 'i')
		n = va_arg(lst, unsigned int);
	else
		n = va_arg(lst, int);
	s = ft_itoa(n);
	n = write(1, s, ft_strlen(s));
	free(s);
	return ((int)n);
}
