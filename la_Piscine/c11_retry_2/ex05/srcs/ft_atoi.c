/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 03:07:13 by ghahn             #+#    #+#             */
/*   Updated: 2022/06/07 01:13:58 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"doop.h"

int	is_space(char x)
{
	if ((x >= 9 && x <= 13) || x == 32)
		return (1);
	return (0);
}

int	ft_atoi(char *s)
{
	int	number;
	int	minus;

	minus = 1;
	number = 0;
	while (is_space(*s))
		s++;
	while (*s == '-' || *s == '+')
	{
		if (*s == '-')
			minus *= -1;
		s++;
	}
	while (*s <= '9' && *s >= '0')
		number = number * 10 + *(s++) - '0';
	return (number * minus);
}
