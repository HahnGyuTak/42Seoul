/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:21:35 by ghahn             #+#    #+#             */
/*   Updated: 2022/08/24 15:33:43 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_upper(long long n)
{
	if (n <= 0)
		return (0);
	return (print_upper(n / 16) + write(1, &"0123456789ABCDEF"[n % 16], 1));
}

static int	print_lower(long long n)
{
	if (n <= 0)
		return (0);
	return (print_lower(n / 16) + write(1, &"0123456789abcdef"[n % 16], 1));
}

int	print_hex(va_list lst, char x)
{
	int			n;
	long long	k;

	k = va_arg(lst, long long);
	n = 0;
	if (x == 'X')
		n += print_upper(k);
	else
		n += print_lower(k);
	return (n);
}
