/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:36:14 by ghahn             #+#    #+#             */
/*   Updated: 2022/07/09 15:43:09 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char		*tmp;
	const char	*s;

	tmp = (char *) dst;
	s = (char *) src;
	if (dst == src)
		return (dst);
	while (n--)
		*tmp++ = *s++;
	return (dst);
}
