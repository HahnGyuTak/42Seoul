/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 11:22:06 by ghahn             #+#    #+#             */
/*   Updated: 2022/05/25 13:27:57 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	print_non(int non)
{
	char	*h;

	h = "0123456789abcdef";
	write(1, non / 16 + h, 1);
	write(1, non % 16 + h, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned char	x;

	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] > 126)
		{
			write(1, "\\", 1);
			x = (unsigned char)str[i];
			print_non(x);
		}
		else
			write(1, str + i, 1);
		i++;
	}
}
