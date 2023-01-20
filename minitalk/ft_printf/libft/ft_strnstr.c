/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 11:40:53 by ghahn             #+#    #+#             */
/*   Updated: 2022/07/10 15:05:08 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in(const char *str, const char *find)
{
	while (*find)
	{
		if (*str != *find)
			return (0);
		str++;
		find++;
	}
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*tmp;
	size_t	i;
	int		len_needle;

	if (*needle == 0)
		return ((char *)haystack);
	if (!*haystack || !len)
		return (0);
	tmp = (char *)haystack;
	len_needle = ft_strlen(needle);
	i = 0;
	while (i <= (len - len_needle) && tmp[i])
	{
		if (is_in(tmp + i, needle) == 1)
			return (tmp + i);
		i++;
	}
	return (0);
}
