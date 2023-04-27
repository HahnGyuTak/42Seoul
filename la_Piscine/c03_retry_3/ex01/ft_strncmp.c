/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:47:26 by ghahn             #+#    #+#             */
/*   Updated: 2022/05/25 13:35:41 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

unsigned int	str_len01(char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_str_cmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (s1[i] - s2[i]);
	}
	if (s1[i] != '\0' && s2[i] == '\0')
		return (s1[i]);
	else if (s1[i] == '\0' && s2[i] != '\0')
		return (-1 * s2[i]);
	return (0);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	len1;
	unsigned int	len2;

	len1 = str_len01(s1);
	len2 = str_len01(s2);
	if (n <= len1 && n <= len2)
	{
		len1 = 0;
		while (len1 < n)
		{
			if (s1[len1] == s2[len1])
				len1++;
			else
				return (s1[len1] - s2[len1]);
		}
		return (0);
	}
	else
		return (ft_str_cmp(s1, s2));
}
/*
int main()
{
	char s1[10] = "abcdefg ";
	char s2[10] = "abcdefg";
	printf("%d\n", ft_strncmp(s1, s2, 6));
	printf("%d\n", ft_strncmp(s1, s2, 20));
}*/
