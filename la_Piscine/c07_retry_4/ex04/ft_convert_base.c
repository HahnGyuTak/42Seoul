/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:00:36 by ghahn             #+#    #+#             */
/*   Updated: 2022/06/04 19:48:24 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

long	str_len(char *s);

long	ft_atoi_base(char *str, char *base);

int		check_cha(char *s);

long	ft_abs(long n);

void	base_nbr(long n, char *base, char *s, int i)
{
	if (n < str_len(base))
		s[i] = base[n];
	else
	{
		base_nbr(n / str_len(base), base, s, i - 1);
		base_nbr(n % str_len(base), base, s, i);
	}
}

char	*final(long n, char *base)
{
	char	*st;
	int		cnt;
	int		len_base;
	long	tmp;

	tmp = ft_abs(n);
	len_base = str_len(base);
	cnt = 1;
	while (tmp >= (long)len_base)
	{
		cnt++;
		tmp /= (long)len_base;
	}
	st = (char *)malloc(sizeof(char) * (cnt + 2));
	st[cnt] = '\0';
	if (n >= 0)
		base_nbr(n, base, st, cnt - 1);
	else
	{
		st[0] = '-';
		st[cnt + 1] = '\0';
		base_nbr(n * -1, base, st, cnt);
	}
	return (st);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*result;

	if (!check_cha(base_from) || !check_cha(base_to))
		return (0);
	result = final(ft_atoi_base(nbr, base_from), base_to);
	return (result);
}
/*
int main(void)
{
	char str[30] = "  \n --+-21442134368ad13";
	char base_form[11] = "0123456789";
	char base_to[11] = "0123456789";
	printf("%s\n", ft_convert_base(str, base_form, base_to));
}*/
