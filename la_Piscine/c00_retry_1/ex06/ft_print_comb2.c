/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:29:22 by ghahn             #+#    #+#             */
/*   Updated: 2022/05/21 15:36:57 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_co(int flag)
{
	char	p;
	char	q;

	p = ',';
	q = ' ';
	if (flag == 0)
	{
		write(1, &q, 1);
	}
	if (flag == 1)
	{
		write(1, &p, 1);
		write(1, &q, 1);
	}
}

void	print_two(char x, char y, int flag)
{
	write(1, &x, 1);
	write(1, &y, 1);
	print_co(flag);
}

int	num(char x, char y)
{
	int	k;

	k = (x - 48) * 10 + (y - 48);
	return (k);
}

void	two(char x, char y, char z, char r)
{
	int	flag;

	if (num(z, r) <= 99)
	{
		flag = 1;
		print_two(x, y, 0);
		if (num(x, y) == 98)
		{
			flag = 2;
		}
		print_two(z, r, flag);
		if (r >= '0' && r <= '8')
		{
			two(x, y, z, r + 1);
		}
		else if (r == '9')
		{
			two(x, y, ++z, '0');
		}
	}
}

void	ft_print_comb2(void)
{
	char	x;
	char	y;

	x = '0';
	y = '0';
	while (num(x, y) <= 98)
	{
		if (y >= '0' && y <= '8')
		{
			two(x, y, x, y + 1);
			y++;
		}
		else if (y == '9')
		{
			two(x, y, x + 1, '0');
			x++;
			y = '0';
		}
	}
}
