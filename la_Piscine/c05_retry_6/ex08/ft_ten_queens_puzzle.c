/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 19:33:45 by ghahn             #+#    #+#             */
/*   Updated: 2022/05/28 21:09:47 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	print_array(int *x)
{
	int		i;
	char	a;

	i = 0;
	while (i < 10)
	{
		a = x[i] + '0';
		write(1, &a, 1);
		i++;
	}
	a = '\n';
	write(1, &a, 1);
}

int	ft_abs(int x)
{
	if (x < 0)
		return (-1 * x);
	else
		return (x);
}

void	no_queen(int n, int *chess, int i, int *flag)
{
	int	j;

	j = 0;
	while (j < n)
	{
		if (chess[j] == i || ft_abs(n - j) == ft_abs(i - chess[j]))
		{
			*flag = 0;
			break ;
		}
		j++;
	}
}

void	queen(int n, int *chess, int *cnt)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	if (n == 10)
	{
		*cnt += 1;
		print_array(chess);
		return ;
	}
	while (i < 10)
	{
		j = 0;
		flag = 1;
		no_queen(n, chess, i, &flag);
		if (flag)
		{
			chess[n] = i;
			queen(n + 1, chess, cnt);
		}
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	chess[10];
	int	cnt;

	cnt = 0;
	queen(0, chess, &cnt);
	return (cnt);
}
/*
int main(void)
{
	printf("%d", ft_ten_queens_puzzle());
}*/
