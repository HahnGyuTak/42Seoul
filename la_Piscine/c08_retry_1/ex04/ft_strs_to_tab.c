/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:35:12 by ghahn             #+#    #+#             */
/*   Updated: 2022/06/04 22:26:46 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include"ft_stock_str.h"

int	str_len(char *s)
{
	int	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	while (src[cnt] != '\0')
	{
		cnt++;
	}
	while (i <= cnt)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*x;
	int			i;

	i = 0;
	x = (struct s_stock_str *)malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (!x)
		return (0);
	while (i < ac)
	{
		x[i].size = str_len(av[i]);
		x[i].copy = (char *)malloc(sizeof(char) * (x[i].size + 1));
		x[i].str = av[i];
		x[i].copy = ft_strcpy(x[i].copy, av[i]);
		i++;
	}
	x[i].str = 0;
	return (x);
}
