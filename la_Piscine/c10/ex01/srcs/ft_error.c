/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 21:20:43 by ghahn             #+#    #+#             */
/*   Updated: 2022/06/06 21:21:53 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft.h"

void	ft_error(char **argv)
{
	char	b;

	while (read(0, &b, 1) != 0)
	{
		if (errno == 0)
			ft_putchar(b);
		else
		{
			ft_putstr(basename(argv[0]));
			ft_putstr(": stdin: ");
			ft_putstr(strerror(errno));
			ft_putchar('\n');
			return (0);
		}
	}
}
