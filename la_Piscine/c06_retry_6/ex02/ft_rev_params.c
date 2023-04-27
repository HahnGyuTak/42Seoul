/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 21:22:46 by ghahn             #+#    #+#             */
/*   Updated: 2022/05/30 10:49:42 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	printchar(char x)
{
	write(1, &x, 1);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc < 2)
		return (-1);
	i = argc - 1;
	while (i)
	{
		while (*(argv[i]))
			printchar(*(argv[i]++));
		i--;
		printchar('\n');
	}
	return (0);
}
