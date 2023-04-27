/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 12:54:02 by ghahn             #+#    #+#             */
/*   Updated: 2022/07/10 13:24:44 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	length(char const *s, unsigned int start, size_t len)
{
	int	l;

	l = ft_strlen(s);
	if (l - (size_t)start < len)
		return (l - (size_t)start);
	else
		return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	l;
	char	*sub;

	i = start;
	j = 0;
	if (!s)
		return (NULL);
	if ((size_t)start >= ft_strlen(s))
	{
		sub = malloc(1);
		if (!sub)
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}
	l = length(s, start, len);
	sub = (char *)malloc(sizeof(char) * (l + 1));
	if (!sub)
		return (NULL);
	while (s[i] && j < l)
		sub[j++] = s[i++];
	sub[j] = '\0';
	return (sub);
}
