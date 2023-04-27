/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:19:23 by ghahn             #+#    #+#             */
/*   Updated: 2022/05/25 22:57:24 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	print_char(char x)
{
	write(1, &x, 1);
}

void	nbr(unsigned int n)
{
	if (n < 10)
		print_char(n + '0');
	else
	{
		nbr(n / 10);
		print_char(n % 10 + '0');
	}
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		print_char('-');
		nbr(-1 * nb);
	}
	else
		nbr((unsigned int)nb);
}
