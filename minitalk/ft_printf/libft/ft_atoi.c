/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 11:50:10 by ghahn             #+#    #+#             */
/*   Updated: 2022/07/10 12:12:13 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	pass_space(char **tmp)
{
	while ((**tmp >= 9 && **tmp <= 13) || **tmp == ' ')
		(*tmp)++;
}

int	ft_atoi(const char *str)
{
	char		*tmp;
	long long	n;
	int			flag;

	tmp = (char *)str;
	n = 0;
	flag = 1;
	pass_space(&tmp);
	if (*tmp == '-' || *tmp == '+')
	{
		if (*tmp == '-')
			flag = -1;
		tmp++;
	}
	while (*tmp && (*tmp >= '0' && *tmp <= '9'))
	{
		if (n * flag > 2147483647)
			return (-1);
		else if (n * flag < -2147483648)
			return (0);
		else
			n = n * 10 + *tmp - '0';
		tmp++;
	}
	return (flag * n);
}
