/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkingMap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 23:49:57 by ghahn             #+#    #+#             */
/*   Updated: 2023/01/18 08:59:10 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	is_surround_wall(t_MAP *m)
{
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (++j < m->width - 2)
		if (m->map[i][j] != '1')
			return (0);
	i = m->height - 1;
	j = -1;
	while (++j < m->width - 2)
		if (m->map[i][j] != '1')
			return (0);
	i = -1;
	j = 0;
	while (++i < m->height - 1)
		if (m->map[i][j] != '1')
			return (0);
	i = -1;
	j = m->width - 2;
	while (++i < m->height - 1)
		if (m->map[i][j] != '1')
			return (0);
	return (1);
}

int	count_unit(t_MAP *m, char unit)
{
	int		i;
	int		j;
	int		cnt;

	cnt = 0;
	i = -1;
	while (++i < m->height)
	{
		j = -1;
		while (++j < m->width - 1)
			if (m->map[i][j] == unit)
				cnt++;
	}
	return (cnt);
}

int	dfs(t_MAP *m, int i, int j, char **tmp)
{
	tmp[i][j] = '1';
	if (m->map[i][j] == 'E')
		return (1);
	if (i + 1 < m->height && tmp[i + 1][j] != '1')
		if (dfs(m, i + 1, j, tmp))
			return (1);
	if (j + 1 < m->width && tmp[i][j + 1] != '1')
		if (dfs(m, i, j + 1, tmp))
			return (1);
	if (i - 1 >= 0 && tmp[i - 1][j] != '1')
		if (dfs(m, i - 1, j, tmp))
			return (1);
	if (j - 1 >= 0 && tmp[i][j - 1] != '1')
		if (dfs(m, i, j - 1, tmp))
			return (1);
	return (0);
}

int	is_right_map(t_US *s)
{
	char	**tmp;
	int		i;

	if (s == NULL)
		return (0);
	if (count_unit(s->m, 'C') == 0 || count_unit(s->m, 'E') == 0)
		return (0);
	if (!is_surround_wall(s->m))
		return (0);
	tmp = malloc(s->m->height * sizeof(char *));
	i = -1;
	while (++i < s->m->height)
		tmp[i] = ft_strdup(s->m->map[i]);
	if (!dfs(s->m, s->p.y_loc, s->p.x_loc, tmp))
		return (0);
	return (1);
}

void	free_all(t_US *snail)
{
	int		i;

	snail->mlx_ptr = NULL;
	snail->win_ptr = NULL;
	i = -1;
	while (i++ < snail->m->height)
		free(snail->m->map[i]);
	free(snail->m->map);
	free(snail->m);
}
