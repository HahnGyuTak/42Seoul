/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:32:40 by ghahn             #+#    #+#             */
/*   Updated: 2023/01/19 21:41:14 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	move(t_US *snail, int x_loc, int y_loc)
{
	snail->m->map[snail->p.y_loc][snail->p.x_loc] = '0';
	snail->p.x_loc = x_loc;
	snail->p.y_loc = y_loc;
}

void	set_image(t_US *snail)
{
	int		img_w;
	int		img_h;

	img_w = 64;
	img_h = 64;
	snail->img.player = mlx_xpm_file_to_image(snail->mlx_ptr, \
		"./textures/snail_left.xpm", &img_w, &img_h);
	snail->img.player = mlx_xpm_file_to_image(snail->mlx_ptr, \
		"./textures/snail_right.xpm", &img_w, &img_h);
	snail->img.wall = mlx_xpm_file_to_image(snail->mlx_ptr, \
		"./textures/wall.xpm", &img_w, &img_h);
	snail->img.collect = mlx_xpm_file_to_image(snail->mlx_ptr, \
		"./textures/slime.xpm", &img_w, &img_h);
	snail->img.space = mlx_xpm_file_to_image(snail->mlx_ptr, \
		"./textures/space.xpm", &img_w, &img_h);
	snail->img.escape = mlx_xpm_file_to_image(snail->mlx_ptr, \
		"./textures/exit.xpm", &img_w, &img_h);
}

void	move_player(int x, int y, t_US *snail)
{
	int		x_loc;
	int		y_loc;

	x_loc = snail->p.x_loc + x;
	y_loc = snail->p.y_loc + y;
	if (snail->m->map[y_loc][x_loc] == 'E' && \
		snail->p.yummy == snail->m->n_collections)
	{
		move(snail, x_loc, y_loc);
		snail->m->map[y_loc][x_loc] = 'P';
		mlx_destroy_window(snail->mlx_ptr, snail->win_ptr);
		ft_printf("Clear!\n");
		free_all(snail);
		exit(0);
	}
	else if (snail->m->map[y_loc][x_loc] == 'C' || \
			snail->m->map[y_loc][x_loc] == '0')
	{
		move(snail, x_loc, y_loc);
		if (snail->m->map[y_loc][x_loc] == 'C')
			snail->p.yummy++;
		snail->m->map[y_loc][x_loc] = 'P';
		print_map(snail);
		ft_printf("%d\n", ++snail->count_move);
	}
}

int	key_press(int keycode, t_US *snail)
{
	int		img_w;
	int		img_h;

	if (keycode == KEY_W)
		move_player(0, -1, snail);
	else if (keycode == KEY_S)
		move_player(0, 1, snail);
	else if (keycode == KEY_A)
	{
		snail->img.player = mlx_xpm_file_to_image(snail->mlx_ptr, \
		"./textures/snail_left.xpm", &img_w, &img_h);
		move_player(-1, 0, snail);
	}
	else if (keycode == KEY_D)
	{
		snail->img.player = mlx_xpm_file_to_image(snail->mlx_ptr, \
		"./textures/snail_right.xpm", &img_w, &img_h);
		move_player(1, 0, snail);
	}
	else if (keycode == KEY_ESC)
	{
		free_all(snail);
		exit(0);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_US	snail;

	if (argc != 2)
		return (0);
	snail.m = read_map(argv[1]);
	if (!is_right_map(&snail) && ft_printf("Fucking Map File!!\n"))
		return (0);
	init_info(&snail);
	snail.mlx_ptr = mlx_init();
	snail.win_ptr = mlx_new_window(snail.mlx_ptr, (snail.m->width - 1) * 64, \
									snail.m->height * 64, "Fucking Snale");
	if (!snail.win_ptr)
		return (0);
	set_image(&snail);
	print_map(&snail);
	mlx_hook(snail.win_ptr, X_EVENT_KEY_RELEASE, 0, &key_press, &snail);
	mlx_hook(snail.win_ptr, X_EVENT_KEY_EXIT, 0, &window_exit, &snail);
	mlx_loop(snail.mlx_ptr);
	return (0);
}
