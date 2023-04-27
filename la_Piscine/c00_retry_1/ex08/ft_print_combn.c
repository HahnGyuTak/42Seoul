/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 23:38:15 by ghahn             #+#    #+#             */
/*   Updated: 2022/05/21 15:31:18 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char x)
{
	write(1, &x, 1);
}

void	init_char(char x[], int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		x[i] = i + '0';
		i++;
	}
}

void	print_all(char x[], int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		print(x[i]);
		i++;
	}
	if (x[0] - '0' != 10 - n)
	{
		print(',');
		print(' ');
	}
}

void	ft_print_combn(int n)
{
	int		i;
	int		j;
	char	y[10];

	init_char(y, n);
	while (y[0] - '0' <= 10 - n)
	{
		i = n - 1;
		print_all(y, n);
		(y[n - 1])++;
		while (i > 0)
		{
			if (y[i] - '0' > 10 - n + i)
			{
				j = 0;
				y[i] = ++(y[i - 1]) + 1;
				while (i + j < n)
				{
					y[i + j + 1] = y[i + j] + 1;
					j++;
				}
			}
			i--;
		}
	}
}
