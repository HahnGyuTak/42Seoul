/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:21:49 by ghahn             #+#    #+#             */
/*   Updated: 2022/09/22 20:17:26 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_integer(va_list lst, char x)
{
	long long	n;
	char		*s;

	if (x == 'u')
		n = (long long)va_arg(lst, unsigned int);
	else
		n = (long long)va_arg(lst, int);
	s = ft_itoa(n);
	if (s == NULL)
		return (-1);
	n = write(1, s, ft_strlen(s));
	if (n == -1)
		return (-1);
	free(s);
	return ((int)n);
}
