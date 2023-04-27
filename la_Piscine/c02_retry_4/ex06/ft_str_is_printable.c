/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 23:15:54 by ghahn             #+#    #+#             */
/*   Updated: 2022/05/22 15:37:33 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	stie(char *st)
{
	int	i;

	i = 0;
	while (st[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	if (stie(str) == 0)
	{
		return (1);
	}
	while (i < stie(str))
	{
		if (str[i] < 32 || str[i] > 126)
		{
			return (0);
		}
		i++;
	}
	return (1);
}
