/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 20:57:04 by ghahn             #+#    #+#             */
/*   Updated: 2022/07/15 20:59:51 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_char(char x, int fd)
{
	write(fd, &x, 1);
}

static void	nbr(unsigned int n, int fd)
{
	if (n < 10)
		print_char(n + '0', fd);
	else
	{
		nbr(n / 10, fd);
		print_char(n % 10 + '0', fd);
	}
}

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb < 0)
	{
		print_char('-', fd);
		nbr(-1 * nb, fd);
	}
	else
		nbr((unsigned int)nb, fd);
}
