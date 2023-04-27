/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 20:05:15 by ghahn             #+#    #+#             */
/*   Updated: 2022/06/06 21:25:46 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft.h"

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		ft_error(argv);
	else
	{
		i = 0;
		while (++i < argc)
		{
			if (read_file(argv[i]) == -1)
			{
				ft_putstr(basename(argv[0]));
				ft_putstr(": ");
				ft_putstr(argv[i]);
				ft_putstr(": ");
				ft_putstr(strerror(errno));
				ft_putchar('\n');
			}
		}
	}
	return (0);
}
