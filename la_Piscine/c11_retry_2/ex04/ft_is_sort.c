/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 03:01:09 by ghahn             #+#    #+#             */
/*   Updated: 2022/06/08 13:08:50 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	flag;

	i = -1;
	flag = 1;
	while (++i < length - 1 && flag)
		if (f(tab[i], tab[i + 1]) < 0)
			flag = 0;
	if (!flag)
	{
		flag = 1;
		i = -1;
		while (++i < length - 1)
			if (f(tab[i], tab[i + 1]) > 0)
				return (0);
	}
	return (1);
}
