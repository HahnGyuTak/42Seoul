/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 11:09:39 by ghahn             #+#    #+#             */
/*   Updated: 2022/05/23 21:05:58 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	str_llennn(char *st)
{
	int	i;

	i = 0;
	while (st[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (*(src + i) && size-- > 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (str_llennn(src));
}
