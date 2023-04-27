/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 22:27:37 by ghahn             #+#    #+#             */
/*   Updated: 2022/06/04 19:45:48 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	str_len(char *s)
{
	long	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

long	ft_abs(long n)
{
	if (n >= 0)
		return (n);
	else
		return (-1 * n);
}

long	ft_atoi_base(char *str, char *base)
{
	long	num;
	long	p;
	long	i;

	p = 1;
	num = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '-' || *str == '+')
		if (*str++ == '-')
			p *= -1;
	i = 0;
	while (*str && i < str_len(base))
	{
		if (*str == base[i])
		{
			num = num * str_len(base) + i;
			str++;
			i = -1;
		}
		i++;
	}
	return (num * p);
}

int	check_cha(char *s)
{
	char			x;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (str_len(s) < 2)
		return (0);
	while (s[i])
	{
		if (*(s + i) == '-' || *(s + i) == '+' || s[i] == ' '
			|| (s[i] >= 9 && s[i] <= 13))
			return (0);
		x = s[i];
		if (i < str_len(s) - 1)
		{
			j = i + 1;
			while (j < str_len(s))
			{
				if (s[j++] == x)
					return (0);
			}
		}
		i++;
	}
	return (1);
}
