/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:52:36 by ghahn             #+#    #+#             */
/*   Updated: 2022/05/28 14:10:09 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

unsigned int	len(char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	f_putchar(char x)
{
	write(1, &x, 1);
}

void	base_nbr(unsigned int n, char *base, unsigned int len)
{
	if (n < len)
		f_putchar(*(base + n));
	else
	{
		base_nbr(n / len, base, len);
		f_putchar(*(base + n % len));
	}
}

int	check_char(char *s)
{
	char				x;
	unsigned int		i;
	unsigned int		j;

	i = 0;
	while (s[i])
	{
		if (*(s + i) == '-' || *(s + i) == '+')
			return (0);
		x = s[i];
		if (i < len(s) - 1)
		{
			j = i + 1;
			while (j < len(s))
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

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	l;

	l = len(base);
	if (l > 1 && check_char(base))
	{
		if (nbr >= 0)
			base_nbr(nbr, base, l);
		else
		{
			f_putchar('-');
			base_nbr(nbr * -1, base, l);
		}
	}
}
/*
int main(void)
{
	char base[20] = "0123456789";
	char base1[20] = "01";
	char base2[20] = "0123456789ABCDEF";
	char base3[20] = "poneyvif";
	char base4[20] = "poneyviff";
	int nbr = -4523816;
	int nbr1 = -2147483648;
	ft_putnbr_base(nbr, base); printf("\n");
	ft_putnbr_base(nbr, base1); printf("\n");
	ft_putnbr_base(nbr, base2); printf("\n");
	ft_putnbr_base(nbr, base3); printf("\n");
	ft_putnbr_base(nbr, base4); printf("\n");
	ft_putnbr_base(nbr1, base); printf("\n");
	ft_putnbr_base(nbr1, base1); printf("\n");
	ft_putnbr_base(nbr1, base2); printf("\n");
	ft_putnbr_base(nbr1, base3); printf("\n");
	ft_putnbr_base(nbr1, base4); printf("\n");
}*/
