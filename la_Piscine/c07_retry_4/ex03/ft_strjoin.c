/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:22:03 by ghahn             #+#    #+#             */
/*   Updated: 2022/06/05 19:58:59 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	s_len(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	all_of_size(int size, char **s, char *sep)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < size)
	{
		len += s_len(s[i]);
		if (i != size - 1)
			len += s_len(sep);
		i++;
	}
	return (len);
}

char	*scat(int size, char **strs, char *sep, char *str)
{
	int	i;
	int	j;
	int	k;
	int	len;

	i = 0;
	j = 0;
	len = all_of_size(size, strs, sep);
	while (i < len)
	{
		k = 0;
		while (strs[j][k] != '\0')
			str[i++] = strs[j][k++];
		k = 0;
		while (sep[k] != '\0' && j < size - 1)
			str[i++] = sep[k++];
		j++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		i;

	i = 0;
	if (size == 0)
	{
		result = (char *)malloc(sizeof(char));
		return (result);
	}
	result = (char *)malloc(sizeof(char) * (all_of_size(size, strs, sep) + 1));
	if (!result)
		return (0);
	return (scat(size, strs, sep, result));
}
