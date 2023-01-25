/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:23:57 by ghahn             #+#    #+#             */
/*   Updated: 2023/01/25 20:22:19 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	window_exit(t_US *snail)
{
	free_all(snail);
	exit(0);
	return (0);
}

void	free_character(char ***p, int height)
{
	char	**tmp;
	int		i;

	i = -1;
	tmp = *p;
	while (++i < height)
		free(tmp[i]);
	free(*p);
}

void	free_all(t_US *snail)
{
	int		i;

	snail->mlx_ptr = NULL;
	snail->win_ptr = NULL;
	i = -1;
	free_character(&snail->m->map, snail->m->height);
	free(snail->m);
}
