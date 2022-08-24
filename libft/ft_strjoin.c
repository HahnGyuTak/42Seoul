/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 13:22:18 by ghahn             #+#    #+#             */
/*   Updated: 2022/07/10 13:34:45 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	size_t	l1;
	size_t	l2;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	i = -1;
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
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
