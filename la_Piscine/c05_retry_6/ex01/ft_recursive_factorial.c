/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:00:34 by ghahn             #+#    #+#             */
/*   Updated: 2022/05/28 15:11:41 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 1 || nb == 0)
		return (1);
	else
	{
		nb = ft_recursive_factorial(nb - 1) * nb;
		return (nb);
	}
}
/*
int main(void)
{
	printf("%d\n%d", ft_recursive_factorial(5), ft_recursive_factorial(4));
}*/
