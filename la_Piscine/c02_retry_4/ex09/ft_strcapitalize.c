/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 10:37:37 by ghahn             #+#    #+#             */
/*   Updated: 2022/05/23 20:20:11 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	str_lelnn(char *st)
{
	int	i;

	i = 0;
	while (st[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	upper(char *x)
{
	if (*x >= 'a' && *x <= 'z')
	{
		*x -= 32;
	}
}

int	word(char *x)
{
	if (*x >= 'A' && *x <= 'Z')
		return (1);
	if (*x >= 'a' && *x <= 'z')
		return (1);
	if (*x >= '0' && *x <= '9')
		return (1);
	return (0);
}

void	check(char *str, int i)
{
	if (i == 1)
		upper(str + i - 1);
	if (!word(str + i - 1))
		upper(str + i);
	else
		if (str[i] <= 'Z' && str[i] >= 'A')
			str[i] += 32;
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 1;
	while (*(str + i))
	{
		check(str, i);
		i++;
	}
	return (str);
}
