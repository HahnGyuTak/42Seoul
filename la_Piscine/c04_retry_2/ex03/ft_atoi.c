/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:23:28 by ghahn             #+#    #+#             */
/*   Updated: 2022/06/01 16:53:48 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	make_num(char *s)
{
	int	num;

	num = 0;
	while (*s >= '0' && *s <= '9')
	{
		num = num * 10 + *s - '0';
		s++;
	}
	return (num);
}

int	is_space(char x)
{
	if (x >= 9 && x <= 13)
		return (1);
	if (x == 32)
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	p;
	int	num;
	int	i;

	i = 0;
	p = 1;
	num = 0;
	while (is_space(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			p *= -1;
		i++;
	}
	if (str[i] && *(str + i) >= '0' && *(str + i) <= '9')
		num = make_num(str + i);
	return (num * p);
}
/*
int main(void)
{
	char x[30] = "---+--+1234ab567";
	printf("%d", ft_atoi(x));
}*/
