/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 03:07:05 by ghahn             #+#    #+#             */
/*   Updated: 2022/06/07 01:11:36 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doop.h"

void	calculate(int a, char x, int b, int (**f)(int, int))
{
	if (x == '+')
		ft_putnbr(f[0](a, b));
	if (x == '-')
		ft_putnbr(f[1](a, b));
	if (x == '*')
		ft_putnbr(f[2](a, b));
	if (x == '/')
	{
		if (b == 0)
			write(1, "Stop : division by zero", 23);
		else
			ft_putnbr(f[3](a, b));
	}
	if (x == '%')
	{
		if (b == 0)
			write(1, "Stop : modulo by zero", 21);
		else
			ft_putnbr(f[4](a, b));
	}
}

void	operator(char *a, char *x, char *b)
{
	int	p;
	int	q;
	int	(*fu[5])(int, int);

	fu[0] = ft_add;
	fu[1] = ft_sub;
	fu[2] = ft_mul;
	fu[3] = ft_div;
	fu[4] = ft_mod;
	if (*x != '-' && *x != '+' && *x != '/' && *x != '%' && *x != '*')
		ft_putchar('0');
	else
	{
		p = ft_atoi(a);
		q = ft_atoi(b);
		calculate(p, *x, q, fu);
	}
	ft_putchar('\n');
}

int	main(int argc, char **argv)
{
	if (argc == 4)
		operator(argv[1], argv[2], argv[3]);
	return (0);
}
