/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 21:43:18 by ghahn             #+#    #+#             */
/*   Updated: 2022/05/22 13:22:13 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

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
