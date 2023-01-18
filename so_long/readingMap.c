/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readingMap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 00:06:24 by ghahn             #+#    #+#             */
/*   Updated: 2023/01/18 08:52:09 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	init_map(t_MAP **x)
{
	*x = (t_MAP *)malloc(sizeof(t_MAP));
	(*x)->height = 0;
	(*x)->width = 0;
	(*x)->map = NULL;
}

void	init_info(t_US *snail)
{
	int		i;
	int		j;

	i = -1;
	while (++i < snail->m->height)
	{
		j = -1;
		while (++j < snail->m->width - 1)
		{
			if (snail->m->map[i][j] == 'P')
			{
				snail->p.x_loc = j;
				snail->p.y_loc = i;
			}
			else if (snail->m->map[i][j] == 'C')
				snail->m->n_collections++;
		}
	}
	snail->p.yummy = 0;
	snail->count_move = 0;
}

int	add_map(t_MAP *m, char *line)
{
	char	**temp_map;
	char	*tmp;
	int		i;

	if (!line)
		return (0);
	tmp = NULL;
	temp_map = (char **)malloc((m->height + 1) * sizeof(char *));
	if (m->map)
		tmp = *(m->map);
	i = -1;
	while (++i < m->height)
		temp_map[i] = m->map[i];
	temp_map[i] = line;
	if (m->map)
		free(m->map);
	if (++(m->height) && !m->width)
		m->width += ft_strlen(line);
	m->map = temp_map;
	return (1);
}

t_MAP	*read_map(char *name)
{
	int		file;
	char	*line;
	t_MAP	*my_map;

	file = open(name, O_RDONLY);
	if (file < 0)
		return (NULL);
	init_map(&my_map);
	while (1)
	{
		line = get_next_line(file);
		if (!add_map(my_map, line))
			break ;
	}
	my_map->n_collections = 0;
	return (my_map);
}

void	print_map(t_US *snail)
{
	int		i;
	int		j;

	i = -1;
	while (++i < snail->m->height)
	{
		j = -1;
		while (++j < snail->m->width - 1)
		{
			mlx_put_image_to_window(snail->mlx_ptr, snail->win_ptr, \
									snail->img.space, j * 64, i * 64);
			if (snail->m->map[i][j] == '1')
				mlx_put_image_to_window(snail->mlx_ptr, snail->win_ptr, \
										snail->img.wall, j * 64, i * 64);
			else if (snail->m->map[i][j] == 'P')
				mlx_put_image_to_window(snail->mlx_ptr, snail->win_ptr, \
										snail->img.player, j * 64, i * 64);
			else if (snail->m->map[i][j] == 'C')
				mlx_put_image_to_window(snail->mlx_ptr, \
							snail->win_ptr, snail->img.collect, j * 64, i * 64);
			else if (snail->m->map[i][j] == 'E')
				mlx_put_image_to_window(snail->mlx_ptr, snail->win_ptr, \
										snail->img.escape, j * 64, i * 64);
		}
	}
}
