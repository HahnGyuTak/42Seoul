/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:26:20 by ghahn             #+#    #+#             */
/*   Updated: 2022/05/24 19:43:50 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	str_len04(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;

	i = 0;
	if (*to_find == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			while (j < str_len04(to_find))
			{
				if (str[i + j] != to_find[j])
					break ;
				j++;
			}
		}
		if (j == str_len04(to_find))
			return (str + i);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char a[20] = "needle in a gyutak";
	char b[10] = " ie";
	char *p = ft_strstr(a, b);
	if (p == NULL) printf("NULL");
	else printf("%s", p);
}*/
