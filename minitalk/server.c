/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:08:42 by ghahn             #+#    #+#             */
/*   Updated: 2023/01/20 21:58:42 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int signal_num;

void	transform(int signum)
{
	static int		i;
	//char	c;

	signal_num *= 2;
	if (signum == SIGUSR2 && ft_printf(" 1"))
		signal_num++;
	else if (signum == SIGUSR1)
		ft_printf(" 0");
	i++;
	if (i == 8)
	{	
		if (signal_num == 127)
			ft_printf("\n");
		else
			ft_printf("[%c]", (unsigned char)signal_num);
		signal_num = 0;
		i = 0;
	}
}

int main()
{
	int	pid;

	pid = getpid();

	ft_printf("pid : %d\n", pid);
	signal(SIGUSR1, transform);
	signal(SIGUSR2, transform);
	while (1)
		pause();
	return (0);
}