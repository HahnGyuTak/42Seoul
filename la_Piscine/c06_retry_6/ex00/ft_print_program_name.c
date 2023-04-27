/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 21:06:26 by ghahn             #+#    #+#             */
/*   Updated: 2022/06/02 16:30:56 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	main(int argc, char **argv)
{
	int		i;
	char	x;

	argc = 0;
	i = 0;
	while (argv[0][i])
		write(1, argv[0] + i++, 1);
	x = '\n';
	write(1, &x, 1);
	return (0);
}
