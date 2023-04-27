/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:56:58 by ghahn             #+#    #+#             */
/*   Updated: 2022/05/30 15:08:25 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_prime(int nb)
{
	unsigned int	i;

	i = 2;
	if (nb <= 1)
		return (0);
	while (i * i <= (unsigned int)nb)
	{
		if ((unsigned int)nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (!is_prime(nb))
		nb++;
	return (nb);
}
/*
int main(void)
{
	printf("%d\n", ft_find_next_prime(-1972));
	printf("%d\n", ft_find_next_prime(0));
	printf("%d\n", ft_find_next_prime(205910));
	printf("%d\n", ft_find_next_prime(339344));
	printf("%d\n", ft_find_next_prime(2));
}*/
