/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 16:08:23 by ghahn             #+#    #+#             */
/*   Updated: 2022/09/12 12:48:34 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	size_t	l1;
	size_t	l2;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	i = -1;
	l1 = ft_strlen(s1);	l2 = ft_strlen(s2);
	tmp = (char *)malloc(sizeof(char) * (l1 + l2 + 1));
	if (!tmp)
		return (0);
	while (++i < l1)
		tmp[i] = s1[i];
	i = -1;
	while (++i < l2)
		tmp[l1 + i] = s2[i];
	tmp[l1 + i] = '\0';
	return (tmp);
}

char	*ft_strdup(const char *s1)
{
	char	*tmp;
	int		len;
	int		i;

	i = -1;
	len = 0;
	while (s1[len])
		len++;
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (0);
	while (s1[++i])
		tmp[i] = s1[i];
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*tmp;

	tmp = (char *)s;
	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == (char)c)
			return (tmp + i);
		i++;
	}
	if (c == 0)
		return (tmp + i);
	return (0);
}
