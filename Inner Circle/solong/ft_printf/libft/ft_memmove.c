/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:43:18 by ghahn             #+#    #+#             */
/*   Updated: 2022/07/10 15:04:43 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*tmp;
	const char	*s;

	tmp = (char *)dst;
	s = (char *)src;
	if (dst == src || len == 0)
		return (dst);
	if (dst < src)
	{
		while (len--)
			*tmp++ = *s++;
	}
	else
	{
		tmp += len;
		s += len;
		while (len--)
			*--tmp = *--s;
	}
	return (dst);
}
