/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:21:18 by ghahn             #+#    #+#             */
/*   Updated: 2022/09/11 18:41:32 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_hex_upper(unsigned long long n)
{
	if (n <= 0)
		return (0);
	return (print_hex_upper(n / 16) + write(1, &"0123456789abcdef"[n % 16], 1));
}

int	print_address(va_list lst)
{
	unsigned long long	tmp;

	tmp = va_arg(lst, unsigned long long);
	if (tmp == 0)
		return (write(1, "0x0", 3));
	return (write(1, "0x", 2) + print_hex_upper(tmp));
}
