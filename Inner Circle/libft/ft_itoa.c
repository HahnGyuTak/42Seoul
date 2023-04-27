/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 20:04:39 by ghahn             #+#    #+#             */
/*   Updated: 2022/07/15 20:24:47 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(long long n)
{
	int			len;
	long long	tmp;

	if (n < 0)
		tmp = -1 * n;
	else if (n > 0)
		tmp = n;
	else
		return (1);
	len = 0;
	while (tmp)
	{
		tmp /= 10;
		len++;
	}
	return (len);
}

static void	put_nbr(long long n, char *s, int i)
{
	if (n < 10)
		s[i] = n + '0';
	else
	{
		put_nbr(n / 10, s, i - 1);
		put_nbr(n % 10, s, i);
	}
}

char	*ft_itoa(int n)
{
	int			len;
	char		*result;
	long long	n2;

	n2 = n;
	len = int_len(n2);
	if (n2 >= 0)
	{
		result = (char *)malloc(sizeof(char) * (len + 1));
		if (!result)
			return (NULL);
		result[len] = '\0';
		put_nbr(n2, result, len - 1);
	}
	else
	{
		result = (char *)malloc(sizeof(char) * (len + 2));
		if (!result)
			return (NULL);
		result[0] = '-';
		result[len + 1] = '\0';
		put_nbr(n2 * -1, result, len);
	}
	return (result);
}
