/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:08:42 by ghahn             #+#    #+#             */
/*   Updated: 2023/01/23 02:49:06 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	transform(int signum)
{
	static int	i = 0;
	static int	num = 0;

	num *= 2;
	if (signum == SIGUSR2)
		num++;
	i++;
	if (i == 8)
	{	
		if (num == 0)
			ft_putchar_fd('\n', 1);
		else
			ft_printf("%c", num);
		num = 0;
		i = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("Server PID : %d\n", pid);
	if (signal(SIGUSR1, transform) == SIG_ERR && ft_printf("SIGINT Error!\n"))
		return (0);
	if (signal(SIGUSR2, transform) == SIG_ERR && ft_printf("SIGINT Error!\n"))
		return (0);
	while (1)
		pause();
	return (0);
}
