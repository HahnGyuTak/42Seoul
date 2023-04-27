/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:47:14 by ghahn             #+#    #+#             */
/*   Updated: 2022/05/23 15:40:00 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

char	*ft_strcat(char *dest, char *src)
{
	char	*x;

	x = dest;
	while (*dest != '\0')
		dest++;
	while (*src != '\0')
		*(dest++) = *(src++);
	*dest = '\0';
	return (x);
}
/*
int	main(void)
{
	char s[5] = "abcd";
	char *k = "ABCD";
	char *p = ft_strcat(s, k);
	write(1, p, 8);
}*/
