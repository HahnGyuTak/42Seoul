/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:35:12 by ghahn             #+#    #+#             */
/*   Updated: 2022/05/31 22:10:15 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long long	i;

	i = 2;
	if (nb == 1 || nb == 0)
		return (nb);
	else if (nb < 0)
		return (0);
	while (i * i <= nb)
	{
		if (nb % i == 0)
			if (i * i == nb)
				return (i);
		i++;
	}
	return (0);
}
/*
int main(void)
{
	printf("%d\n%d", ft_sqrt(625), ft_sqrt(1402961785));
}*/
