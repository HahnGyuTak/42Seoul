/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:27:49 by ghahn             #+#    #+#             */
/*   Updated: 2022/05/23 15:39:52 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*x;

	x = dest;
	while (*dest)
		dest++;
	while (*src && nb--)
		*(dest++) = *(src++);
	*dest = '\0';
	return (x);
}
