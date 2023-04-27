/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 12:03:05 by ghahn             #+#    #+#             */
/*   Updated: 2022/06/01 13:26:30 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	*ft_range(int min, int max)
{
	int	*result;
	int	*tmp;

	if (min >= max)
		return (0);
	result = (int *)malloc(sizeof(int) * (max - min));
	if (result == NULL)
		return (0);
	tmp = result;
	while (max - min)
		*tmp++ = min++;
	return (result);
}
/*
int main(void)
{
	int i = 0;
	while (i < 4)
		printf("%d\n", ft_range(4,8)[i++]);
}*/
