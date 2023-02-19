/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:40:38 by ghahn             #+#    #+#             */
/*   Updated: 2023/01/25 18:41:44 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	is_num(char *s)
{
	while (*s)
		if (!ft_isdigit(*s++))
			return (0);
	return (1);
}

void	send_char(int pid, int b)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (1 & (b >> (7 - i)))
		{
			if (kill(pid, SIGUSR2) == -1 && ft_printf("kill Error!\n"))
				return ;
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1 && ft_printf("kill Error!\n"))
				return ;
		}
		i++;
		usleep(100);
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
	if (argc != 3 || !is_num(argv[1]))
		return (ft_printf("Error\nEnter ./client [PID] [Message]\n") && 0);
	send_signal(ft_atoi(argv[1]), argv[2]);
}
