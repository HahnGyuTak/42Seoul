/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 15:05:30 by ghahn             #+#    #+#             */
/*   Updated: 2022/07/15 20:04:25 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tmp;
	int		i;
	int		j;
	int		idx;

	i = 0;
	idx = 0;
	if (!s1 || !set)
		return (NULL);
	j = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (s1[j - 1] && ft_strchr(set, s1[j - 1]) && j > 1)
		j--;
	if (i > j)
		return (ft_strdup(""));
	tmp = (char *)malloc(sizeof(char) * (j - i + 1));
	if (!tmp)
		return (0);
	while (i < j)
		tmp[idx++] = s1[i++];
	tmp[idx] = '\0';
	return (tmp);
}
