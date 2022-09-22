/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:18:08 by ghahn             #+#    #+#             */
/*   Updated: 2022/08/23 14:18:08 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	form_print(va_list lst, char x)
{
	char	re[2];

	if (x == 'c' || x == 's')
		return (print_string(lst, x));
	else if (x == 'p')
		return (print_address(lst));
	else if (x == 'd' || x == 'i' || x == 'u')
		return (print_integer(lst, x));
	else if (x == 'x' || x == 'X')
		return (print_hex(lst, x));
	else if (x == '%')
		return (write(1, "%", 1));
	else
	{
		re[0] = x;
		re[1] = '\0';
		return (write(1, re, 1));
	}
	return (-1);
}

int	ft_printf(const char *s, ...)
{
	va_list	x;
	int		result;
	int		flage;

	if (s == NULL)
		return (-1);
	result = 0;
	va_start(x, s);
	while (*s)
	{
		if (*s != '%')
			result += write(1, s, 1);
		else
		{
			flage = form_print(x, *++s);
			if (flage == -1)
				return (-1);
			result += flage;
		}
		s++;
	}
	va_end(x);
	return (result);
}
