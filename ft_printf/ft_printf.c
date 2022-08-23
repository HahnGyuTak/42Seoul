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

int 	form_print(va_list lst, char x)
{
	if (x == 'c' || x == 's')
		return (print_string(lst, x));
	if (x == 'p')
		return (print_address(lst));
	if (x == 'd' || x == 'i' || x == 'u')
		return (print_integer(lst, x));
	if (x == 'x' || x == 'X')
		return (print_hex(lst, x));
	if (x == '%')
		return (write(1, "%", 1));
}

int	ft_printf(const char *s, ...)
{
	va_list	x;
	int		result;
	char	*tmp;

	if (s == NULL)
		return (-1);
	result = 0;
	va_start(x, s);
	va_arg(tmp, char *);
	while (*s)
	{
		if (*s != '%')
			result += write(1, *s, 1);
		else
			result += form_print(x, *++s);
		s++;
	}
	va_end(x);
	return (result);
}