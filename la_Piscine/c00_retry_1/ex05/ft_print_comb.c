/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:52:44 by ghahn             #+#    #+#             */
/*   Updated: 2022/05/21 15:38:18 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	num_com(char x, char y, char z)
{
	char	q;
	char	p;

	q = ',';
	p = ' ';
	write(1, &x, 1);
	write(1, &y, 1);
	write(1, &z, 1);
	if (x != '7')
	{
		write(1, &q, 1);
		write(1, &p, 1);
	}
}

void	ft_print_comb(void)
{
	char	a;
	char	b;
	char	c;

	a = '0';
	b = '1';
	c = '2';
	while (a <= '7')
	{
		while (b <= '8')
		{
			while (c <= '9')
			{
				num_com(a, b, c);
				c++;
			}
			c = ++b + 1;
		}
		b = ++a + 1;
		c = b + 1;
	}
}
