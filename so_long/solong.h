/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:46:16 by ghahn             #+#    #+#             */
/*   Updated: 2023/01/18 08:58:53 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# define KEY_ESC			53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define X_EVENT_KEY_PRESS   2
# define X_EVENT_KEY_RELEASE   3
# define X_EVENT_KEY_EXIT   17
# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include "get_next_line/get_next_line.h"

typedef struct t_PLAYER
{
	int		x_loc;
	int		y_loc;
	int		yummy;
}	t_PLAYER;

typedef struct t_MAP
{
	int		width;
	int		height;
	char	**map;
	int		n_collections;
}	t_MAP;

typedef struct t_IMG
{
	void	*player;
	void	*wall;
	void	*collect;
	void	*space;
	void	*escape;
}	t_IMG;

typedef struct UpsetSnail
{
	t_IMG		img;
	t_PLAYER	p;
	t_MAP		*m;
	void		*mlx_ptr;
	void		*win_ptr;
	int			count_move;
}	t_US;

void	init_info(t_US *snail);
int		key_press(int keycode, t_US *snail);
t_MAP	*read_map(char *name);
void	print_map(t_US *snail);
int		is_right_map(t_US *s);
void	free_all(t_US *snail);
#endif