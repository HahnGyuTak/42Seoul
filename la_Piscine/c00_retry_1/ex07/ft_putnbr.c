/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:23:19 by ghahn             #+#    #+#             */
/*   Updated: 2022/05/21 15:34:50 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char i)
{
	write(1, &i, 1);
}

void	tt(unsigned int nb)
{
	char	i;

	if (nb > 9)
	{
		i = nb % 10 + 48;
		tt(nb / 10);
		ft_putchar(i);
	}
	else
	{
		i = nb + 48;
		ft_putchar(i);
	}
}

void	ft_putnbr(int nb)
{
	char	i;

	i = '-';
	if (nb < 0)
	{
		ft_putchar(i);
		tt(nb * -1);
	}
	else
	{
		tt(nb);
	}
}
