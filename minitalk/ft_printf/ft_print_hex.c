/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:21:35 by ghahn             #+#    #+#             */
/*   Updated: 2022/09/22 20:06:37 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_upper(long long n)
{
	int	tmp;

	if (n <= 0)
		return (0);
	tmp = print_upper(n / 16);
	if (tmp == -1)
		return (-1);
	if (write(1, &"0123456789ABCDEF"[n % 16], 1) == -1)
		return (-1);
	return (++tmp);
}

static int	print_lower(long long n)
{
	int	tmp;

	if (n <= 0)
		return (0);
	tmp = print_lower(n / 16);
	if (tmp == -1)
		return (-1);
	if (write(1, &"0123456789abcdef"[n % 16], 1) == -1)
		return (-1);
	return (++tmp);
}

int	print_hex(va_list lst, char x)
{
	int			n;
	long long	k;

	k = va_arg(lst, unsigned int);
	n = 0;
	if (k == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		n++;
	}
	else
	{
		if (x == 'X')
			n += print_upper(k);
		else
			n += print_lower(k);
	}
	return (n);
}
