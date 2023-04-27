/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:45:55 by ghahn             #+#    #+#             */
/*   Updated: 2022/06/06 12:44:42 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	print_char(char x)
{
	write(1, &x, 1);
}

void	nbr(int n)
{
	if (n < 0)
	{
		print_char('-');
		nbr(-1 * n);
	}
	else if (n < 10)
		print_char(n + '0');
	else
	{
		nbr(n / 10);
		print_char(n % 10 + '0');
	}
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		ft_putstr(par[i].str);
		print_char('\n');
		nbr(par[i].size);
		print_char('\n');
		ft_putstr(par[i].copy);
		print_char('\n');
		i++;
	}
}
