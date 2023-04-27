/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 20:51:03 by ghahn             #+#    #+#             */
/*   Updated: 2022/06/06 22:40:43 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft.h"

int	read_file(char *filepath)
{
	int		f;
	char	buffer[BUFF];
	int		size;

	f = open(filepath, O_RDONLY);
	if (f == -1)
		return (-1);
	else
	{
		size = read(f, buffer, BUFF);
		while (size != 0)
		{
			ft_putstr(buffer);
			size = read(f, buffer, BUFF);
		}
	}
	close(f);
}
