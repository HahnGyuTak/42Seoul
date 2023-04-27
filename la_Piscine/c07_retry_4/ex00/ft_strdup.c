/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:21:06 by ghahn             #+#    #+#             */
/*   Updated: 2022/06/01 13:25:44 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	st_len(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*copy;
	int		i;

	i = 0;
	copy = (char *)malloc(sizeof(char) * (st_len(src) + 1));
	if (copy == NULL)
		return (0);
	while (*src)
		copy[i++] = *src++;
	copy[i] = '\0';
	return (copy);
}
/*
int	main(void)
{
	char x[15] = "I am king";
	char *y = ft_strdup(x);
	printf("%s\n", y);
}*/
