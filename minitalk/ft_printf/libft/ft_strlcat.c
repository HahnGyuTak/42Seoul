/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:26:44 by ghahn             #+#    #+#             */
/*   Updated: 2022/07/09 18:31:41 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_d;

	j = 0;
	i = ft_strlen(dest);
	len_d = i;
	while (src[j] && i + 1 < size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (i <= size)
		dest[i] = '\0';
	if (len_d >= size)
		return (ft_strlen(src) + size);
	return (len_d + ft_strlen(src));
}
