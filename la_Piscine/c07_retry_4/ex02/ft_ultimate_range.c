/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:01:32 by ghahn             #+#    #+#             */
/*   Updated: 2022/06/04 22:17:47 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*tmp;

	i = 0;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	tmp = (int *)malloc(sizeof(int) * (max - min));
	if (!tmp)
		return (-1);
	while (i < max - min)
	{
		tmp[i] = min + i;
		i++;
	}
	*range = tmp;
	return (max - min);
}
/*
int main(void)
{
	int i = 0;
	int *x;
	ft_ultimate_range(&x, 4, 8);
	while (i < 4)
		printf("%d\n", x[i++]);
}*/
