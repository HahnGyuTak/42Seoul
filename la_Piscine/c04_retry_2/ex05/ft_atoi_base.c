/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 12:20:35 by ghahn             #+#    #+#             */
/*   Updated: 2022/06/02 14:09:26 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	stlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	checking(char *s, char x)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (x == s[i])
			return (1);
		i++;
	}
	return (0);
}

int	check_cha(char *s)
{
	char	x;
	int		i;
	int		j;

	i = 0;
	while (s[i])
	{
		if (*(s + i) == '-' || *(s + i) == '+'
			|| (s[i] >= 9 && s[i] <= 13) || s[i] == 32)
			return (0);
		x = s[i];
		if (i < stlen(s) - 1)
		{
			j = i + 1;
			while (j < stlen(s))
			{
				if (s[j] == x)
					return (0);
				j++;
			}
		}
		i++;
	}
	return (1);
}

int	num_base(char *base, char *str, int len)
{
	int	i;
	int	j;
	int	num;

	num = 0;
	j = 0;
	while (*str && i < len)
	{
		if (*str == base[i])
		{
			num = num * len + i;
			str++;
			i = -1;
		}
		i++;
	}
	return (num);
}

int	ft_atoi_base(char *str, char *base)
{
	int	num;
	int	p;

	p = 1;
	num = 0;
	if (stlen(base) > 1 && check_cha(base))
	{
		while (*str)
		{
			if (checking(base, *str))
			{
				num = num_base(base, str, stlen(base));
				break ;
			}
			else if ((*str >= 9 && *str <= 13) || *str == 32)
				p *= 1;
			else if (*str != '-' && *str != '+')
				break ;
			else if (*str == '-')
				p *= -1;
			str++;
		}
		return (p * num);
	}
	return (0);
}
/*
int main(void)
{
	char base[20] = "0123456789";
	char base1[20] = "01";
	char base2[20] = "0123456789ABCDEF";
	char base3[20] = "poneyvif";
	char base4[20] = "poneyviff";
	printf("%d\n", ft_atoi_base("4523816", base));
	printf("%d\n", ft_atoi_base("10001010000011100101000", base1));
	printf("%d\n", ft_atoi_base("450728", base2));
	printf("%d\n", ft_atoi_base("   nonpeyvp", base3));
	printf("%d\n", ft_atoi_base("nonpeyvp", base4));
	printf("%d\n", ft_atoi_base("-2147483648", base));
	printf("%d\n", ft_atoi_base("     -10000000000000000000000000000000", base1));
	printf("%d\n", ft_atoi_base("   -80000000", base2));
	printf("%d\n", ft_atoi_base("-npppppppppp", base3));
}*/
