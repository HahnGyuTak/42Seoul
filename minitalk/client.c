/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:40:38 by ghahn             #+#    #+#             */
/*   Updated: 2023/01/22 23:20:40 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
void	send_char(int pid, int b)
{
	int	i;
	int	j;

	i = 0;
	while (i < 8)
	{
		if (1 & (b >> (7 - i)))
				kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i++;
		j = 0;
		while (j < 10)
		{
			usleep(10);
			j++;
		}
	}
}

void	send_signal(int pid, char *m)
{
	int	j;

	j = -1;
	while (m[++j])
	{
		send_char(pid, m[j]);
	}
	send_char(pid, '\0');
}

int	main(int argc, char *argv[])
{
	if (argc != 3)
		return (ft_printf("Error\nEnter ./client [PID] [Message]\n") && 0);
	send_signal(ft_atoi(argv[1]), argv[2]);
}
